type article = {
  id: int,
  title: string,
  description: string,
  date: string,
  tags: list(string),
  url: string,
  comments: int,
  reactions: int,
};

module Decode = {
  open Json.Decode;

  let article = json => {
    id: json |> field("id", int),
    title: json |> field("title", string),
    description: json |> field("description", string),
    date: json |> field("readable_publish_date", string),
    tags: json |> field("tag_list", list(string)),
    url: json |> field("url", string),
    comments: json |> field("comments_count", int),
    reactions: json |> field("positive_reactions_count", int),
  };

  let articles = list(article);
};

type result('a, 'b) =
  | Ok('a)
  | Fail('b);

module Utils = {
  let something_went_wrong = _err =>
    Fail("Something went wront...") |> Js.Promise.resolve;

  let handle_response = res => {
    Js.Promise.(
      Fetch.Response.(
        if (ok(res)) {
          res |> json |> then_(j => resolve(Ok(j)));
        } else {
          res |> json |> then_(j => resolve(Fail(j)));
        }
      )
    );
  };
};

module Fetch = {
  let fetch = (url, success_decoder) =>
    Js.Promise.(
      Fetch.fetch(url)
      |> then_(Utils.handle_response)
      |> then_(either_json =>
          resolve(
            switch (either_json) {
            | Ok(res) => Ok(success_decoder(res))
            | Fail(_) => Fail("Something went wrong...")
            },
          )
        )
      |> catch(Utils.something_went_wrong)
    );
};
