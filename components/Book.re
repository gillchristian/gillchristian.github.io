type book = {
  title: string,
  url: string
};

[@react.component]
let make = (~book as {title, url}) => {
    <div className="talk">
      <p className="talk-title">
        <a href=url target="_blank" rel="noopener noreferrer">
        <b> {ReasonReact.string(title)} </b>
        </a>
      </p>
    </div>;
};

let default = make;
