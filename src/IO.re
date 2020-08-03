[%raw "require('isomorphic-fetch')"];

type article = {
  id: int,
  title: string,
  date: string,
  tags: list(string),
  url: string,
};

module Decode = {
  open Json.Decode;

  let article = json => {
    id: field("id", int, json),
    title: field("title", string, json),
    date: field("readable_publish_date", string, json),
    tags: field("tag_list", list(string), json),
    url: field("url", string, json),
  };

  let articles = list(article);

  let topic = json => (
    field("topic_label", string, json),
    optional(field("topic_url", string), json),
  );

  let past_event = json: Events.past_event => {
    start_date: field("start_date", string, json),
    end_date: field("end_date", string, json),
    topic: topic(json),
    description: optional(field("description", string), json),
    vod: optional(field("vod", string), json),
  };

  let future_event = json: Events.future_event => {
    start_date: field("start_date", string, json),
    topic: optional(topic, json),
    description: optional(field("description", string), json),
  };

  let events = json => (
    field("past", list(past_event), json),
    field("future", list(future_event), json),
  );
};

type result('a, 'b) =
  | Ok('a)
  | Fail('b);

module Utils = {
  let something_went_wrong = _err =>
    Fail("Something went wront...") |> Js.Promise.resolve;

  let handle_response = res =>
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
