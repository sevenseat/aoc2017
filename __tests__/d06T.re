open Jest;

open Expect;

test("rebalance : 0, 2, 7, 0", () =>
  D06.rebalance([|0, 2, 7, 0|]) |> expect |> toEqual([|2, 4, 1, 2|])
);

test("rebalance : 2, 4, 1, 2", () =>
  D06.rebalance([|2, 4, 1, 2|]) |> expect |> toEqual([|3, 1, 2, 3|])
);

test("rebalance : 3, 1, 2, 3", () =>
  D06.rebalance([|3, 1, 2, 3|]) |> expect |> toEqual([|0, 2, 3, 4|])
);

test("rebalance : 0, 2, 3, 4", () =>
  D06.rebalance([|0, 2, 3, 4|]) |> expect |> toEqual([|1, 3, 4, 1|])
);

test("rebalance : 1, 3, 4, 1", () =>
  D06.rebalance([|1, 3, 4, 1|]) |> expect |> toEqual([|2, 4, 1, 2|])
);

test("part1 - test", () =>
  D06.part1([|0, 2, 7, 0|]) |> expect |> toEqual(5)
);

test("part2 - test", () =>
  D06.part2([|0, 2, 7, 0|]) |> expect |> toEqual(4)
);

let testVal = [|14, 0, 15, 12, 11, 11, 3, 5, 1, 6, 8, 4, 9, 1, 8, 4|];

test("part1", () =>
  D06.part1(testVal) |> expect |> toEqual(11137)
);

test("part2", () =>
  D06.part2(testVal) |> expect |> toEqual(1037)
);