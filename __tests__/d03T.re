open Jest;

open Expect;

test("1", () =>
  DayThree.part1(1) |> expect |> toBe(0)
);

test("12", () =>
  DayThree.part1(12) |> expect |> toBe(3)
);

test("23", () =>
  DayThree.part1(23) |> expect |> toBe(2)
);

test("1024", () =>
  DayThree.part1(1024) |> expect |> toBe(31)
);

test("277678", () =>
  DayThree.part1(277678) |> expect |> toBe(475)
);