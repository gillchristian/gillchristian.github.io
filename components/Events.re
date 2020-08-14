type topic = (string, option(string));

type past_event = {
  start_date: string,
  end_date: string,
  topic,
  description: EventDescription.description,
  vod: option(string),
};

type future_event = {
  start_date: string,
  topic: option(topic),
  description: EventDescription.description,
};

type events = (list(past_event), list(future_event));

type future_eventType =
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
  let make = (~event as {end_date, topic, description, vod}: past_event) =>
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
      <p className="event-content-lg">
        {
          ReasonReact.string(
            "Finished "
            ++ Utils.Time.fromNow(end_date)
            ++ " ("
            ++ Utils.Time.formatDate(end_date)
            ++ ")",
          )
        }
      </p>
      <EventDescription description />
      {
        switch (vod) {
        | Some(url) =>
          <div className="event-content-lg">
            <a href=url target="_blank" rel="noopener noreferrer">
              {ReasonReact.string({js|Recording 👀|js})}
            </a>
          </div>
        | None => ReasonReact.null
        }
      }
    </div>;

  let default = make;
};

module FutureEvent = {
  [@react.component]
  let make = (~event as {start_date, topic, description}, ~eventType) =>
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
      <p className="event-content-lg">
        {
          ReasonReact.string(
            "Starts "
            ++ Utils.Time.fromNow(start_date)
            ++ " ("
            ++ Utils.Time.formatDate(start_date)
            ++ ")",
          )
        }
      </p>
      <EventDescription description />
    </div>;

  let default = make;
};
