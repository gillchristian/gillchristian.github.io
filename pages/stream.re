open Utils.Fn;

let channel = "https://twitch.tv/gillchristian";

let discord = "https://discord.gg/UMdeMUq";

let declarative_tv = "https://declarative.tv/";

let url = "https://api.jsonbin.io/b/5f14a3e4918061662844bcd6/latest";

type tabs =
  | Future
  | Past;

let activeCx = (x, y) => x === y ? Some("active") : None;

let handle_description =
  fun
  | None => None
  | Some(desc) =>
    Some(
      desc
      |> EventDescription.parse_description
      |> Either.mapLeft(const(desc)),
    );

let past_event = (event: IO.past_event): Events.past_event => {
  start_date: event.start_date,
  end_date: event.end_date,
  topic: event.topic,
  description: handle_description(event.description),
  vod: event.vod,
};
let future_event = (event: IO.future_event): Events.future_event => {
  start_date: event.start_date,
  topic: event.topic,
  description: handle_description(event.description),
};

let decode_events_description = ((past, future)) => (
  List.map(past_event, past),
  List.map(future_event, future),
);

[@react.component]
let make = () => {
  let (events, setEvents) = React.useState(() => RemoteData.NotAsked);
  let (tab, setTab) = React.useState(() => Future);

  React.useEffect0(() => {
    setEvents(_ => RemoteData.Loading);

    Js.Promise.(
      IO.Fetch.fetch(url, IO.Decode.events)
      |> then_(res =>
           (
             switch (res) {
             | IO.Ok(es) =>
               setEvents(_ =>
                 RemoteData.Success(decode_events_description(es))
               )
             | IO.Fail(error) => setEvents(_ => RemoteData.Failure(error))
             }
           )
           |> resolve
         )
      |> ignore
    );

    None;
  });

  <div className="Site">
    <Nav />
    <div className="Site-content">
      <h1 className="events-title">
        {ReasonReact.string("Stream schedule")}
      </h1>
      <h2 className="events-title-stream">
        <a href=channel target="_blank" rel="noopener noreferrer">
          {ReasonReact.string("twitch.tv/gillchristian")}
        </a>
        { ReasonReact.string(" / ") }
        <a href=discord target="_blank" rel="noopener noreferrer">
          {ReasonReact.string("Discord #ttv_gillchristian")}
        </a>
      </h2>
      <p>
        { ReasonReact.string("I code random side projects, while some are watching. Mostly in strongly typed functional languages like Haskell and PureScript.") }
      </p>
      <p>
        { ReasonReact.string("Come say Hi and chat, or just lurk if that's your thing.") }
      </p>

      <div className="events-list">
        <div className="events-tabs">
          <h3
            className={
              Style.cx([Some("events-tab"), activeCx(Future, tab)])
            }
            onClick=(_ => setTab(_ => Future))>
            {ReasonReact.string("Upcoming")}
          </h3>
          <h3
            className={
              Style.cx([Some("events-tab"), activeCx(Past, tab)])
            }
            onClick=(_ => setTab(_ => Past))>
            {ReasonReact.string("Past")}
          </h3>
        </div>
        {
          switch ((tab, events)) {
          | (_, RemoteData.NotAsked) =>
            <span className="feedback">
              {ReasonReact.string({js|⌛ Loading ...|js})}
            </span>
          | (_, RemoteData.Loading) =>
            <span className="feedback">
              {ReasonReact.string({js|⌛ Loading ...|js})}
            </span>
          | (Past, RemoteData.Success((past, _))) =>
            past
            |> List.map(event => <Events.PastEvent event />)
            |> Array.of_list
            |> ReasonReact.array
          | (Future, RemoteData.Success((_, future))) =>
            switch (future) {
            | [] =>
              <div>
                <p className="feedback">
                  {ReasonReact.string({js|🤦 No streams planned ...|js})}
                </p>
                <p className="feedback">
                  {ReasonReact.string("Maybe another FP streamer is live? ")}
                  <a href=declarative_tv target="_blank" rel="noopener noreferrer">
                    {ReasonReact.string("declarative.tv")}
                  </a>
                </p>

              </div>
            | [next, ...rest] =>
              <React.Fragment>
                <Events.FutureEvent event=next eventType=Events.Next />
                {
                  rest
                  |> List.map(event =>
                        <Events.FutureEvent
                          event
                          eventType=Events.Future
                        />
                      )
                  |> Array.of_list
                  |> ReasonReact.array
                }
              </React.Fragment>
            }
          | (_, RemoteData.Failure(err)) =>
            <span> {ReasonReact.string(err)} </span>
          }
        }
      </div>
    </div>
    <Footer />
  </div>;
};

let default = make;
