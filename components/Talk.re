type talk_type =
  | Meetup
  | Conference
  | Lightning
  | Podcast
  | Workshop;

let talk_icon =
  fun
  | Meetup => {js|💬|js}
  | Conference => {js|🔊|js}
  | Lightning => {js|⚡|js}
  | Podcast => {js|🎙|js}
  | Workshop => {js|👨‍🏫|js};

type link = {
  url: string,
  label: string,
};

type talk = {
  title: string,
  event: string,
  eventUrl: string,
  description: string,
  date: string,
  links: list(link),
  talk_type,
};

[@react.component]
let make =
    (~talk as {title, event, eventUrl, description, date, links, talk_type}) =>
  <div className="talk">
    <p className="talk-title">
      {ReasonReact.string(talk_icon(talk_type) ++ " ")}
      <b> {ReasonReact.string(title)} </b>
    </p>
    <p>
      <a href=eventUrl target="_blank" rel="noopener noreferrer">
        {ReasonReact.string(event)}
      </a>
      <span> {ReasonReact.string(" - " ++ date)} </span>
    </p>
    <p> {ReasonReact.string(description)} </p>
    <p>
      {
        links
        |> List.mapi((i, {url, label}) =>
             i == 0 ?
               <a key=url href=url target="_blank" rel="noopener noreferrer">
                 {ReasonReact.string(label)}
               </a> :
               <span key=url>
                 {ReasonReact.string(" | ")}
                 <a href=url target="_blank" rel="noopener noreferrer">
                   {ReasonReact.string(label)}
                 </a>
               </span>
           )
        |> Array.of_list
        |> ReasonReact.array
      }
    </p>
  </div>;

let default = make;
