[@react.component]
let make = (~tags) =>
  <code>
    {ReasonReact.string("[ ")}
    {tags |> String.concat(", ") |> ReasonReact.string}
    {ReasonReact.string(" ]")}
  </code>;

let default = make;
