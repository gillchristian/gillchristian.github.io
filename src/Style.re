let cx = classes =>
  List.fold_right(
    (c, cc) =>
      switch (c) {
      | Some(className) => cc ++ " " ++ className
      | None => cc
      },
    classes,
    "",
  );
