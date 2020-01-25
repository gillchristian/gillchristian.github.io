let articles: list(IO.article) = [
  {
    id: 81136,
    title: "tsearch first public version",
    description: "A more detailed view on how the tsearch PoC is implemented",
    date: "Feb  6 '19",
    tags: ["typescript", "devtools", "ideas", "devlog"],
    url: "https://dev.to/gillchristian/tsearch-first-public-version-50a",
    comments: 0,
    reactions: 0,
  },
  {
    id: 79115,
    title: "A crazy idea and a proof of concept",
    description: "How I came up the idea of building a TypeScript search tool and what's next.",
    date: "Jan 30 '19",
    tags: ["typescript", "devtools", "ideas", "devlog"],
    url: "https://dev.to/gillchristian/a-crazy-idea-and-a-proof-of-concept-2oj7",
    comments: 0,
    reactions: 0,
  }
];

[@react.component]
let make = () => {
  <div className="Site">
    <Nav />

    <div className="Site-content">
      <h1> {ReasonReact.string("Tsearch Blog")} </h1>

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

