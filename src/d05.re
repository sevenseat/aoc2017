let rec jump1 = (arr, curPos, curStep) =>
  switch (curPos) {
  | p when p < 0 || p >= Array.length(arr) => curStep
  | _ =>
    let jumpTo = curPos + arr[curPos];
    arr[curPos] = arr[curPos] + 1;
    jump1(arr, jumpTo, curStep + 1);
  };

let part1 = arr => jump1(arr, 0, 0);

let rec jump2 = (arr, curPos, curStep) =>
  switch (curPos) {
  | p when p < 0 || p >= Array.length(arr) => curStep
  | _ =>
    let jumpTo = curPos + arr[curPos];
    arr[curPos] = arr[curPos] >= 3 ? arr[curPos] - 1 : arr[curPos] + 1;
    jump2(arr, jumpTo, curStep + 1);
  };

let part2 = arr => jump2(arr, 0, 0);
