open Utils.Fn;

let channel = "https://twitch.tv/gillchristian";

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
      </h2>
      <div className="events-list">
        {
          switch (events) {
          | RemoteData.NotAsked =>
            <span> {ReasonReact.string("Loading ...")} </span>
          | RemoteData.Loading =>
            <span> {ReasonReact.string("Loading ...")} </span>
          | RemoteData.Success((past, future)) =>
            <React.Fragment>
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
                switch (tab) {
                | Past =>
                  past
                  |> List.map(event => <Events.PastEvent event />)
                  |> Array.of_list
                  |> ReasonReact.array
                | Future =>
                  switch (future) {
                  | [] =>
                    <div> {ReasonReact.string("No streams planned =(")} </div>
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
                }
              }
            </React.Fragment>
          | RemoteData.Failure(err) =>
            <span> {ReasonReact.string(err)} </span>
          }
        }
      </div>
    </div>
    <Footer />
  </div>;
};

let default = make;
