[@react.component]
let make = () =>
  <div className="home-wrapper">
    <div className="home-logo">
      <div className="home-avatar" />
      <h1 className="home-title"> {ReasonReact.string("Christian Gill")} </h1>
    </div>
    <big> <big> <div className="home-header"> <Header /> </div> </big> </big>
    <Social />
  </div>;

let default = make;
