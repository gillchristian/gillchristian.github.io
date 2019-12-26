module Link = {
  [@react.component]
  let make = (~href, ~children) => {
    let pathname = switch(Next.Router.useRouter()) {
    | Some(router) => router##pathname
    | None => "/"
    };

    pathname == href
      ? <span className="header-active"> children </span>
      : <Next.Link href=href>
          <a className="header-link"> children </a>
        </Next.Link>;
  };

  let default = make;
};

[@react.component]
let make = () => {
  <div>
    <Link href="/projects"> {ReasonReact.string("Projects")} </Link>

    <Link href="/talks"> {ReasonReact.string("Talks")} </Link>

    <Link href="/articles"> {ReasonReact.string("Articles")} </Link>

    <Link href="/about"> {ReasonReact.string("About")} </Link>
  </div>;
};

let default = make;
