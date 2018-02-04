let chRow = row => {
  let minMax =
    List.fold_left(
      ((cMin, cMax), i) => (min(i, cMin), max(i, cMax)),
      (max_int, min_int),
      row
    );
  snd(minMax) - fst(minMax);
};

let chsum = matrix =>
  List.fold_left((sum, row) => sum + chRow(row), 0, matrix);