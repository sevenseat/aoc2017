let charToInt = ch => Char.code(ch) - Char.code('0');

let explode = s => {
  let rec exp = (i, list) =>
    i < 0 ? list : exp(i - 1, [charToInt(s.[i]), ...list]);
  exp(String.length(s) - 1, []);
};

let rec captchaWorker = (accum, lst) =>
  switch lst {
  | [] => accum
  | [x, y, ...rest] when x === y => captchaWorker(accum + x, [y, ...rest])
  | [_x, ...rest] => captchaWorker(accum, rest)
  };

let captcha = s =>
  [charToInt(s.[String.length(s) - 1]), ...explode(s)] |> captchaWorker(0);

let split = (list, n) => {
  let rec aux = (i, acc) =>
    fun
    | [] => (List.rev(acc), [])
    | [h, ...t] as l =>
      if (i == 0) {
        (List.rev(acc), l);
      } else {
        aux(i - 1, [h, ...acc], t);
      };
  aux(n, [], list);
};

let part2 = s => {
  let spList = split(explode(s), String.length(s) / 2);
  List.fold_left2(
    (accum, i1, i2) => i1 === i2 ? accum + i1 + i2 : accum,
    0,
    fst(spList),
    snd(spList)
  );
};