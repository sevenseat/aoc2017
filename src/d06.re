let getDistPos = banks => {
  let maxPos = ref(0);
  Belt.Array.forEachWithIndex(banks, (i, _) =>
    maxPos := banks[i] > banks[maxPos^] ? i : maxPos^
  );
  maxPos^;
};

let rebalance = banks => {
  let banks = Array.copy(banks);
  let rec helper = (curPos, toDist) => {
    let curPos = curPos == Array.length(banks) ? 0 : curPos;
    switch (toDist) {
    | 0 => banks
    | _ =>
      banks[curPos] = banks[curPos] + 1;
      helper(curPos + 1, toDist - 1);
    };
  };
  let redistPos = getDistPos(banks);
  let toRedist = banks[redistPos];
  banks[redistPos] = 0;
  helper(redistPos + 1, toRedist);
};

let getCycle = (banks: array(int)) => {
  let rec helper = (banks, map, n) => {
    /* Oh god this is horrible */
    let hashStr =
      Belt.Array.reduce(banks, "", (acc, cur) =>
        acc ++ string_of_int(cur) ++ ","
      );
    Belt.Map.String.has(map, hashStr) ?
      (n, n - Belt.Map.String.getExn(map, hashStr)) :
      helper(rebalance(banks), Belt.Map.String.set(map, hashStr, n), n + 1);
  };
  helper(banks, Belt.Map.String.empty, 0);
};

let part1 = banks => banks |> getCycle |> fst;

let part2 = banks => banks |> getCycle |> snd;