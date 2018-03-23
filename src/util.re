let charToInt = ch => Char.code(ch) - Char.code('0');

let intToChar = i => Char.chr(i + Char.code('0'));

let explode = s => {
  let rec exp = (i, list) =>
    i < 0 ? list : exp(i - 1, [charToInt(s.[i]), ...list]);
  exp(String.length(s) - 1, []);
};