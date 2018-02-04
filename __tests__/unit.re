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

test("Day 2", () =>
  DayTwo.chsum([[5, 1, 9, 5], [7, 5, 3], [2, 4, 6, 8]]) |> expect |> toBe(18)
);