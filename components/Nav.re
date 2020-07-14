[@react.component]
let make = () =>
  <div className="nav-wrapper">
    <h3 className="nav-title">
      <Header.Link href="/" className="nav-logo">
        <div className="nav-avatar" />
        {ReasonReact.string("Christian Gill")}
      </Header.Link>
    </h3>
    <Header />
  </div>;

let default = make;
