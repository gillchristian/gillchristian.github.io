[@react.component]
let make = (~article as {title, date, tags, url}: IO.article) =>
  <div className="article">
    <div className="article-title">
      <a href=url target="_blank" rel="noopener noreferrer">
        {ReasonReact.string(title)}
      </a>
    </div>
    <small>
      <span className="article-interactions">
        {ReasonReact.string(date ++ " ")}
      </span>
      <Tags tags />
    </small>
  </div>;

let default = make;
