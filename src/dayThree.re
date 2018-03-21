let diameter = sq => {
  let nextOdd = n => n mod 2 == 0 ? n + 1 : n;
  sq |> float |> sqrt |> ceil |> truncate |> nextOdd;
};

let part1 = sq =>
  switch (sq) {
  | 1 => 0
  | _ =>
    let d = diameter(sq);
    let stepsOut = (d - 1) / 2;
    let perimStart = (d - 2) * (d - 2) + 1;
    let pos = (sq - perimStart) mod (d - 1);
    let stepsSide = abs(pos + 1 - stepsOut);
    stepsOut + stepsSide;
  };