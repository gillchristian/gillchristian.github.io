type t('d) =
  | NotAsked
  | Loading
  | Success('d)
  | Failure(string);

let is_loading = rd =>
  switch (rd) {
  | Loading => true
  | _ => false
  };

let map = (f, rd) =>
  switch (rd) {
  | Success(d) => Success(f(d))
  | x => x
  };

let chain = (f, rd) =>
  switch (rd) {
  | Success(d) => f(d)
  | x => x
  };
