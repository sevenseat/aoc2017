let chRow = row => {
  let minMax =
    List.fold_left(
      ((cMin, cMax), i) => (min(i, cMin), max(i, cMax)),
      (max_int, min_int),
      row,
    );
  snd(minMax) - fst(minMax);
};

let part1 = matrix =>
  List.fold_left((sum, row) => sum + chRow(row), 0, matrix);

let rec findDivisor = list => {
  let rec findHelper = (i, list) =>
    switch (list) {
    | [] => None
    | [h, ..._t] when h / i * i === h => Some(h / i)
    | [h, ..._t] when i / h * h === i => Some(i / h)
    | [_h, ...t] => findHelper(i, t)
    };
  switch (list) {
  | [] => None
  | [h, ...t] =>
    switch (findHelper(h, t)) {
    | None => findDivisor(t)
    | Some(div) => Some(div)
    }
  };
};

let part2 = matrix =>
  List.fold_left(
    (sum, row) =>
      switch (sum, findDivisor(row)) {
      | (None, _)
      | (_, None) => None
      | (Some(sum), Some(div)) => Some(sum + div)
      },
    Some(0),
    matrix,
  );
