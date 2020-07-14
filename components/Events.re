type topic = (string, option(string));

type pastEvent = {
  date: string,
  topic,
  description: option(string),
};

type futureEvent = {
  date: string,
  topic: option(topic),
  description: option(string),
};

type events = (list(pastEvent), list(futureEvent));

type futureEventType =
  | Next
  | Future;

let eventCx = eventType =>
  switch (eventType) {
  | Next => "next"
  | Future => "future"
  };

let channel = "https://twitch.tv/gillchristian";

module PastEvent = {
  [@react.component]
  let make = (~event as {date, topic, description}: pastEvent) =>
    <div className="event past">
      <div className="event-title">
        {
          switch (topic) {
          | (t, Some(u)) =>
            <a href=u target="_blank" rel="noopener noreferrer">
              {ReasonReact.string(t)}
            </a>
          | (t, None) =>
            <a href=channel target="_blank" rel="noopener noreferrer">
              {ReasonReact.string(t)}
            </a>
          }
        }
      </div>
      <p className="event-date">
        {
          ReasonReact.string(
            "Finished "
            ++ Utils.Time.fromNow(date)
            ++ " ("
            ++ Utils.Time.formatDate(date)
            ++ ")",
          )
        }
      </p>
      <p className="event-description">
        {
          Belt.Option.mapWithDefault(
            description,
            ReasonReact.null,
            ReasonReact.string,
          )
        }
      </p>
    </div>;

  let default = make;
};

module FutureEvent = {
  [@react.component]
  let make = (~event as {date, topic, description}, ~eventType) =>
    <div className={Style.cx([Some("event"), Some(eventCx(eventType))])}>
      <div className="event-title">
        {
          switch (topic) {
          | Some((t, url)) =>
            <a
              href={Belt.Option.getWithDefault(url, channel)}
              target="_blank"
              rel="noopener noreferrer">
              {ReasonReact.string(t)}
            </a>
          | None =>
            <a href=channel target="_blank" rel="noopener noreferrer">
              {ReasonReact.string("TBD")}
            </a>
          }
        }
      </div>
      <p className="event-date">
          {
            ReasonReact.string(
              "Starts "
              ++ Utils.Time.fromNow(date)
              ++ " ("
              ++ Utils.Time.formatDate(date)
              ++ ")",
            )
          }
      </p>
      <p className="event-description">
        {
          Belt.Option.mapWithDefault(
            description,
            ReasonReact.null,
            ReasonReact.string,
          )
        }
      </p>
    </div>;

  let default = make;
};

[@react.component]
let make = (~events as (past, future)) =>
  <React.Fragment>
    {
      past
      |> List.map(event => <PastEvent event />)
      |> Array.of_list
      |> ReasonReact.array
    }
    {
      switch (future) {
      | [] => <div> {ReasonReact.string("No streams planned =(")} </div>
      | [next, ...rest] =>
        <React.Fragment>
          <FutureEvent event=next eventType=Next />
          {
            rest
            |> List.map(event => <FutureEvent event eventType=Future />)
            |> Array.of_list
            |> ReasonReact.array
          }
        </React.Fragment>
      }
    }
  </React.Fragment>;

let default = make;
