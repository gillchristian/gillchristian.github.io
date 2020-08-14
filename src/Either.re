type either('left, 'right) =
  | Left('left)
  | Right('right);

let mapLeft = (f, e) =>
  switch (e) {
  | Left(l) => Left(f(l))
  | Right(r) => Right(r)
  };
