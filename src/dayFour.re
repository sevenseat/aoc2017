let isValid = (wordMap, phrase) => {
  open Belt.Set.String;
  let rec helper = (words, set) =>
    switch (words) {
    | [] => true
    | [x, ..._] when has(set, x) => false
    | [x, ...xs] => helper(xs, add(set, x))
    };
  let words =
    Js.String.split({| |}, phrase) |> Array.to_list |> List.map(wordMap);
  helper(words, empty);
};

let part1 = phrases =>
  List.filter(phrase => isValid(word => word, phrase), phrases)
  |> List.length;

let sortWord = word =>
  Js.String.split("", word)
  |> Js.Array.sortInPlace
  |> Array.fold_left((++), "");

let part2 = phrases =>
  List.filter(phrase => isValid(sortWord, phrase), phrases) |> List.length;