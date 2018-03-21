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

let part1 = (banks: array(int)) => {
  let rec helper = (banks, set, n) => {
    /* Oh god this is horrible */
    let hashStr =
      Belt.Array.reduce(banks, "", (acc, cur) =>
        acc ++ string_of_int(cur) ++ ","
      );
    Belt.Set.String.has(set, hashStr) ?
      n : helper(rebalance(banks), Belt.Set.String.add(set, hashStr), n + 1);
  };
  helper(banks, Belt.Set.String.empty, 0);
};