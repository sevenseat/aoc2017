type state =
  | Group
  | Garbage
  | GarbageIgnore;

type token =
  | OpenParen
  | CloseParen;

let part1 = input => {
  let tokenize = input => {
    let rec tok = (inpt, state, tokens) =>
      switch (state, inpt) {
      | (_, []) => List.rev(tokens)
      | (Group, ['{', ...xs]) => tok(xs, Group, [OpenParen, ...tokens])
      | (Group, ['}', ...xs]) => tok(xs, Group, [CloseParen, ...tokens])
      | (Group, ['<', ...xs]) => tok(xs, Garbage, tokens)
      | (Group, [_, ...xs]) => tok(xs, Group, tokens)
      | (Garbage, ['>', ...xs]) => tok(xs, Group, tokens)
      | (Garbage, ['!', ...xs]) => tok(xs, GarbageIgnore, tokens)
      | (Garbage, [_, ...xs]) => tok(xs, Garbage, tokens)
      | (GarbageIgnore, [_, ...xs]) => tok(xs, Garbage, tokens)
      };
    tok(Util.explode(input) |> Belt.List.map(_, Util.intToChar), Group, []);
  };
  let rec score = (toks, curScore, level) =>
    switch (toks) {
    | [] => curScore
    | [OpenParen, ...xs] => score(xs, curScore + level, level + 1)
    | [CloseParen, ...xs] => score(xs, curScore, level - 1)
    };
  let tokens = tokenize(input);
  score(tokens, 0, 1);
};

let part2 = input => {
  let tokenize = input => {
    let rec tok = (inpt, state, tokens) =>
      switch (state, inpt) {
      | (_, []) => List.rev(tokens)
      | (Group, ['<', ...xs]) => tok(xs, Garbage, tokens)
      | (Group, [_, ...xs]) => tok(xs, Group, tokens)
      | (Garbage, ['>', ...xs]) => tok(xs, Group, tokens)
      | (Garbage, ['!', ...xs]) => tok(xs, GarbageIgnore, tokens)
      | (Garbage, [x, ...xs]) => tok(xs, Garbage, [x, ...tokens])
      | (GarbageIgnore, [_, ...xs]) => tok(xs, Garbage, tokens)
      };
    tok(Util.explode(input) |> Belt.List.map(_, Util.intToChar), Group, []);
  };
  input |> tokenize |> List.length;
};