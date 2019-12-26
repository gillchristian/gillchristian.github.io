[@react.component]
let make = (~article as {title, description, date, tags, url, comments, reactions}: IO.article) => {
    <div className="article">
      <p className="article-title">
        <a href=url target="_blank" rel="noopener noreferrer">
          {ReasonReact.string(title)}
        </a>
      </p>

      <p> {ReasonReact.string(description)} </p>

      <p>  
        <small>
          <span className="article-interactions">
            {ReasonReact.string(date ++ " ")}
          </span>

          {reactions > 0
            ? <span className="article-interactions">
                {ReasonReact.string({js|👍|js} ++ string_of_int(reactions))}
              </span>
            : <> </>}
          {comments > 0
            ? <span className="article-interactions">
                {ReasonReact.string({js|💬|js} ++ string_of_int(comments))}
              </span>
            : <> </>}

          <Tags tags />
        </small>
      </p>
    </div>;
};

let default = make;
