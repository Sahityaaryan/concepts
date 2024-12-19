function findPlatform(arr: Array<number>, dep: Array<number>): number {
  // your code here

  arr.sort((a, b) => a - b);
  dep.sort((a, b) => a - b);

  let cnt = 0;
  let platform_required = 0;

  let ap = 0;
  let dp = 0;

  while (ap < arr.length && dp < dep.length) {
    if (arr[ap] > dep[dp]) {
      cnt--;
      dp++;
    } else {
      cnt++;
      ap++;
    }

    platform_required = Math.max(platform_required, cnt);
  }

  return platform_required;
}

// let arr_string = "900, 940, 950, 1100, 1500, 1800";
// let dep_string = "910, 1200, 1120, 1130, 1900, 2000";

// let arr = arr_string.split(" ").map((ele) => +ele);
// let dep = dep_string.split(" ").map((ele) => +ele);

// console.log("minimum number of stations: ", findPlatform(arr, dep));
