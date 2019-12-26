[%raw "require('isomorphic-fetch')"];

let url = "https://dev.to/api/articles?username=gillchristian";

[@react.component]
let make = () => {
  let (articles, setArticles) = React.useState(
    () => RemoteData.NotAsked
  );

  React.useEffect0(() => {
    setArticles((_) => RemoteData.Loading);

    Js.Promise.(
      IO.Fetch.fetch(url, IO.Decode.articles)
      |> then_(res =>
           switch(res) {
           | IO.Ok(articles) => setArticles((_) => RemoteData.Success(articles))
           | IO.Fail(error) => setArticles((_) => RemoteData.Failure(error))
           } |> resolve
         )
      |> ignore
    );

    None;
  });

  <div className="Site">
    <Nav />

    <div className="Site-content">
      <blockquote>
        <p> {ReasonReact.string("I have only one method that I recommended extensively - it's called think before you write.")} </p>
        <p> <i> {ReasonReact.string("Richard Hamming.")} </i> </p>
      </blockquote>

      <h1> {ReasonReact.string("Articles")} </h1>

      {switch(articles) {
      | RemoteData.NotAsked => <span> {ReasonReact.string("loading ...")} </span>
      | RemoteData.Loading => <span> {ReasonReact.string("loading ...")} </span>
      | RemoteData.Success(articles) => 
        <div>
          {articles
            |> List.map((article: IO.article) => <Article key=string_of_int(article.id) article />)
            |> Array.of_list
            |> ReasonReact.array}
        </div>
      | RemoteData.Failure(err) => <span> {ReasonReact.string(err)} </span>
      }}
    </div>

    <Footer />
  </div>;
};

let default = make;
