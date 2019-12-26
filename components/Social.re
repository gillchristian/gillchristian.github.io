[@react.component]
let make = () => {
  <div>
    <a href="https://twitter.com/gillchristian" target="_blank" rel="noopener noreferrer" className="social-link">
      {ReasonReact.string("Twitter")}
    </a>

    <a href="https://github.com/gillchristian" target="_blank" rel="noopener noreferrer" className="social-link">
      {ReasonReact.string("GitHub")}
    </a>

    <a href="https://www.linkedin.com/in/gillchristian/" target="_blank" rel="noopener noreferrer" className="social-link">
      {ReasonReact.string("LinkedIn")}
    </a>
  </div>;
};

let default = make;
