module Link = {
  [@react.component]
  let make = (~href, ~className=?, ~children) => {
    let pathname = switch(Next.Router.useRouter()) {
    | Some(router) => router##pathname
    | None => "/"
    };

    pathname == href
      ? <span className=Style.cx([Some("header-active"), className])>
          children
        </span>
      : <Next.Link href=href>
          <a className=Style.cx([Some("header-link"), className])>
            children
          </a>
        </Next.Link>;
  };

  let default = make;
};

[@react.component]
let make = () => {
  <div>
    <Link href="/projects"> {ReasonReact.string("Projects")} </Link>

    <Link href="/talks"> {ReasonReact.string("Talks")} </Link>

    <Link href="/articles"> {ReasonReact.string("Writing")} </Link>

    <Link href="/about"> {ReasonReact.string("About")} </Link>
  </div>;
};

let default = make;
