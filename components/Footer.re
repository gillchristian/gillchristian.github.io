let year = Js.Date.getFullYear(Js.Date.make());

[@react.component]
let make = () => {
  <footer className="footer">
    <div className="footer-social">
      <Social />
    </div>

    <div className="footer-cr">
      {ReasonReact.string({js|Christian Gill © |js})}
      {year |> Js.Float.toString |> ReasonReact.string}
    </div>
  </footer>;
};

let default = make;
