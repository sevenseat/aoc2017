open Jest;

open Expect;

test("1122", () =>
  DayOne.captcha("1122") |> expect |> toBe(3)
);

test("1111", () =>
  DayOne.captcha("1111") |> expect |> toBe(4)
);

test("1234", () =>
  DayOne.captcha("1234") |> expect |> toBe(0)
);

test("91212129", () =>
  DayOne.captcha("91212129") |> expect |> toBe(9)
);

test("1212", () =>
  DayOne.part2("1212") |> expect |> toBe(6)
);

test("1221", () =>
  DayOne.part2("1221") |> expect |> toBe(0)
);

test("123425", () =>
  DayOne.part2("123425") |> expect |> toBe(4)
);

test("123123", () =>
  DayOne.part2("123123") |> expect |> toBe(12)
);

test("12131415", () =>
  DayOne.part2("12131415") |> expect |> toBe(4)
);

test("Day 2 part 1", () =>
  DayTwo.chsum([[5, 1, 9, 5], [7, 5, 3], [2, 4, 6, 8]])
  |> expect
  |> toBe(18)
);

test("Day 2 part 2 - forward div", () =>
  DayTwo.chDiv([[3, 6]]) |> expect |> toEqual(Some(2))
);

test("Day 2 part 2 - backward div", () =>
  DayTwo.chDiv([[6, 3]]) |> expect |> toEqual(Some(2))
);

test("Day 2 part 2 - no div", () =>
  DayTwo.chDiv([[6, 7]]) |> expect |> toEqual(None)
);

test("Day 2 part 2", () =>
  DayTwo.chDiv([[5, 9, 2, 8]]) |> expect |> toEqual(Some(4))
);

test("Day 2 part 2", () =>
  DayTwo.chDiv([[5, 9, 2, 8], [9, 4, 7, 3], [3, 8, 6, 5]])
  |> expect
  |> toEqual(Some(9))
);