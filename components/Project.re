type project = {
  title: string,
  tags: list(string),
  repo: string,
  url: option(string),
  description: string,
  isExternal: bool
};

[@react.component]
let make = (~project as {title, tags, repo, url, description, isExternal}) => {
    <div className="project">
      <p>
        <b className="project-title"> {ReasonReact.string(title)} </b>
        
        <small>
          {isExternal
            ? {ReasonReact.string(" (contributor) ")}
            : {ReasonReact.string(" ")} }
        </small>
      </p>

      <p> {ReasonReact.string(description)} </p>

      <small>
        <Tags tags />
      </small>

      <p>
        <a href=repo target="_blank" rel="noopener noreferrer">
          {ReasonReact.string("repo")}
        </a>
        {switch(url) {
        | Some(view_url) => (
            <>
              {ReasonReact.string(" | ")}
              <a href=view_url target="_blank" rel="noopener noreferrer">
                {ReasonReact.string("view")}
              </a>
            </>
          )
        | None => <> </>
        }}
      </p>
    </div>;
};

let default = make;
