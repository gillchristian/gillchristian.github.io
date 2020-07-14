let channel = "https://twitch.tv/gillchristian";

let url = "https://api.jsonbin.io/b/5f14a3e4918061662844bcd6/latest";

[@react.component]
let make = () => {
  let (events, setEvents) = React.useState(() => RemoteData.NotAsked);

  React.useEffect0(() => {
    setEvents(_ => RemoteData.Loading);

    Js.Promise.(
      IO.Fetch.fetch(url, IO.Decode.events)
      |> then_(res =>
           (
             switch (res) {
             | IO.Ok(articles) =>
               setEvents(_ => RemoteData.Success(articles))
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
          | RemoteData.Success(events) => <Events events />
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
