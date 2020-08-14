open Either;
open Parse;

type node =
  | Text(string)
  | Link(string, string);

let between_brackets = between(string("["), string("]"));
let between_parens = between(string("("), string(")"));

let until_open_bracket =
  String.concat("") <$> manyTill(anyChar, lookAhead(string("[")));
let until_close_bracket =
  String.concat("") <$> manyTill(anyChar, lookAhead(string("]")));
let until_close_parens =
  String.concat("") <$> manyTill(anyChar, lookAhead(string(")")));

let link_text = between_brackets(until_close_bracket);
let link_url = between_parens(until_close_parens);

let mk_link = (label, url) => Link(label, url);
let link = mk_link <$> link_text <*> link_url;

let mk_text = text => Text(text);
let text = mk_text <$> (String.concat("") <$> many1(anyCharNot("[")));

let parse_description = Parse.parse(many(text <|> link));

type description = option(either(string, list(node)));

[@react.component]
let make = (~description) =>
  <p className="event-content-md">
    {
      switch (description) {
      | None => ReasonReact.null
      | Some(Left(unparsed)) => ReasonReact.string(unparsed)
      | Some(Right(nodes)) =>
        nodes
        |> List.mapi((i, node) =>
             switch (node) {
             | Text(txt) =>
               <span key={string_of_int(i)}>
                 {ReasonReact.string(txt)}
               </span>
             | Link(label, href) =>
               <a
                 key={string_of_int(i)}
                 href
                 target="_blank"
                 rel="noopener noreferrer">
                 {ReasonReact.string(label)}
               </a>
             }
           )
        |> Array.of_list
        |> ReasonReact.array
      }
    }
  </p>;
