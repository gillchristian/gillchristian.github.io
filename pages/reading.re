let books: list(Book.book) = [
  {title: "The Go Programming Language", url: "https://www.gopl.io/"},
  {
    title: "The Pragmatic Programmer",
    url: "https://en.wikipedia.org/wiki/The_Pragmatic_Programmer",
  },
  {
    title: "Haskell Programming From First Principles",
    url: "https://haskellbook.com/",
  },
  {
    title: "The Mythical Man-Month",
    url: "https://en.wikipedia.org/wiki/The_Mythical_Man-Month",
  },
  {
    title: "Professor Frisby's Mostly Adequate Guide to Functional Programming",
    url: "https://github.com/MostlyAdequate/mostly-adequate-guide",
  },
  {
    title: "Never Split The Difference",
    url: "https://info.blackswanltd.com/never-split-the-difference",
  },
  {
    title: "Getting to Yes",
    url: "https://en.wikipedia.org/wiki/Getting_to_Yes",
  },
  {
    title: "The Secret Skills of Productive Programmers",
    url: "https://codewithoutrules.com/secretskills/",
  },
];

let render_book = (book: Book.book) => <Book key={book.title} book />;

[@react.component]
let make = () =>
  <div className="Site">
    <Nav />
    <div className="Site-content">
      <blockquote>
        <p> {ReasonReact.string("...")} </p>
        <p> {ReasonReact.string("...")} </p>
        <p> <i> {ReasonReact.string("John Dow")} </i> </p>
      </blockquote>
      <h2> {ReasonReact.string("Books")} </h2>
      <div>
        {books |> List.map(render_book) |> Array.of_list |> ReasonReact.array}
      </div>
    </div>
    <Footer />
  </div>;

let default = make;
