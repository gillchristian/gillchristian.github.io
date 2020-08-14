open Either;

type parser('a) = string => (string, either(string, 'a));

let parse = (pa: parser('a), str) => str |> pa |> snd;

/* Functor */

let map = (f: 'a => 'b, pa: parser('a)): parser('b) =>
  str =>
    switch (pa(str)) {
    | (rest, Right(a)) => (rest, Right(f(a)))
    | (rest, Left(err)) => (rest, Left(err))
    };

let (<$>) = (f: 'a => 'b, pa: parser('a)): parser('b) => map(f, pa);

/* Applicative */

let pure = (a: 'a): parser('a) => str => (str, Right(a));

let ap = (pa: parser('a), pf: parser('a => 'b)): parser('b) =>
  str =>
    switch (pf(str)) {
    | (rest, Right(f)) => map(f, pa, rest)
    | (rest, Left(err)) => (rest, Left(err))
    };

let (<*>) = (pf: parser('a => 'b), pa: parser('a)): parser('b) =>
  ap(pa, pf);

let ( *> ) = (pa: parser('a), pb: parser('b)): parser('b) =>
  Utils.Fn.const(Utils.Fn.id) <$> pa <*> pb;

let ( <* ) = (pa: parser('a), pb: parser('b)): parser('a) =>
  Utils.Fn.const <$> pa <*> pb;

/* Monad */

let bind = (f: 'a => parser('b), pa: parser('a)): parser('b) =>
  str =>
    switch (pa(str)) {
    | (rest, Right(a)) => f(a, rest)
    | failure => failure
    };

let (>>=) = (pa: parser('a), f: 'a => parser('b)): parser('b) =>
  bind(f, pa);

/* String / Char */

let anyChar: parser(string) =
  str =>
    switch (str) {
    | "" => ("", Left("Unexpected end of input"))
    | str => (
        Js.String.substringToEnd(~from=1, str),
        Right(Js.String.charAt(0, str)),
      )
    };

let anyCharNot: string => parser(string) =
  (not_this, str) =>
    switch (str) {
    | "" => ("", Left("Unexpected end of input"))
    | str when Js.String.charAt(0, str) === not_this => (
        str,
        Left("Unexpected '" ++ Js.String.charAt(0, str) ++ "'"),
      )
    | str => (
        Js.String.substringToEnd(~from=1, str),
        Right(Js.String.charAt(0, str)),
      )
    };

let string: string => parser(string) =
  (substr, str) =>
    switch (str) {
    | "" => ("", Left("Unexpected end of input"))
    | str when Js.String.startsWith(substr, str) => (
        Js.String.replace(substr, "", str),
        Right(substr),
      )
    | str => (
        str,
        Left(
          "Expected '" ++ substr ++ "', got '" ++ Js.String.charAt(0, str),
        ),
      )
    };

/* Combinators */

let (<|>) = (p1: parser('a), p2: parser('a)): parser('a) =>
  str =>
    switch (p1(str)) {
    | (rest, Right(a)) => (rest, Right(a))
    | (rest, Left(_)) when rest === str => p2(rest)
    | (rest, Left(a)) => (rest, Left(a))
    };

let lookAhead: parser('a) => parser('a) =
  (pa, str) =>
    switch (pa(str)) {
    | (_, Right(a)) => (str, Right(a))
    | (rest, Left(err)) => (rest, Left(err))
    };

let manyTill = (pa: parser('a), ending: parser('ending)): parser(list('a)) => {
  let base = Utils.Fn.const([]) <$> ending;

  let rec scan: parser(list('a)) =
    str => (base <|> (Utils.List.cons <$> pa <*> scan))(str);

  scan;
};

let manyTill1 = (pa, ending) =>
  Utils.List.cons <$> pa <*> manyTill(pa, ending);

let many = (pa: parser('a)): parser(list('a)) =>
  input => {
    let rec scan: list('a) => parser(list('a)) =
      (acc, str) =>
        switch (pa(str)) {
        | (rest, Right(a)) => scan(List.append(acc, [a]), rest)
        | (_, Left(_)) => (str, Right(acc))
        };

    scan([], input);
  };

let many1 = pa => Utils.List.cons <$> pa <*> many(pa);

let try_ = (pa: parser('a)): parser('a) =>
  str =>
    switch (pa(str)) {
    | (rest, Right(a)) => (rest, Right(a))
    | (_, Left(err)) => (str, Left(err))
    };

let between = (before, after, p) => before *> p <* after;
