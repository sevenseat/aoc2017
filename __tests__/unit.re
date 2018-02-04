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