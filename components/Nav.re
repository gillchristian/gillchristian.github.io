[@react.component]
let make = () => {
  <div className="nav-wrapper">
    <div className="nav-logo">
      <div className="nav-avatar" />

      <h3 className="nav-title">
        <Header.Link href="/">
          {ReasonReact.string("Christian Gill")}
        </Header.Link>
      </h3>
    </div>

    <Header />
  </div>;
};

let default = make;
