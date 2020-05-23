let articles: list(IO.article) = [
  {
    id: 81136,
    title: "tsearch first public version",
    date: "Feb  6 '19",
    tags: ["typescript", "devtools", "ideas", "devlog"],
    url: "https://dev.to/gillchristian/tsearch-first-public-version-50a",
  },
  {
    id: 79115,
    title: "A crazy idea and a proof of concept",
    date: "Jan 30 '19",
    tags: ["typescript", "devtools", "ideas", "devlog"],
    url: "https://dev.to/gillchristian/a-crazy-idea-and-a-proof-of-concept-2oj7",
  }
];

[@react.component]
let make = () => {
  <div className="Site">
    <Nav />

    <div className="Site-content">
      <h1 className="tsearch-title">
        {ReasonReact.string("Tsearch Blog")}

        <img src="/tsearch-logo.png" className="tsearch-logo" alt="Tsearch" />
     </h1>

      <p>
        <a href="https://tsearch.io"> {ReasonReact.string("Tsearch")} </a>
        {ReasonReact.string(" is a TypeScript search engine. It allows to search functions from packages by name or approximate type signature.")}
      </p>

      <br />

      <div>
        {articles
          |> List.map((article: IO.article) => <Article key=string_of_int(article.id) article />)
          |> Array.of_list
          |> ReasonReact.array}
      </div>
    </div>

    <Footer />
  </div>;
};

let default = make;

