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