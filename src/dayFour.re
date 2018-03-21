let isValid = phrase => {
  open Belt.Set.String;
  let rec helper = (words, set) =>
    switch (words) {
    | [] => true
    | [x, ..._] when has(set, x) => false
    | [x, ...xs] => helper(xs, add(set, x))
    };
  let words = Js.String.split({| |}, phrase) |> Array.to_list;
  helper(words, empty);
};

let part1 = phrases => List.filter(isValid, phrases) |> List.length;