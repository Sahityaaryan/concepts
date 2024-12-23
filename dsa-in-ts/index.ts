function findPlatform(arr: Array<number>, dep: Array<number>): number {
  let arr_dep_array: Array<Array<number>> = [];
  let plt_time: Array<number> = [];

  for (let i in arr) {
    arr_dep_array.push([arr[i], dep[i]]);
  }

  arr_dep_array.sort((a, b) => a[1] - b[1]);

  console.log(arr_dep_array);

  for (let ele of arr_dep_array) {
    let [arrival, departure] = ele;
    let got_platform: boolean = false;
    // console.log("arrival: ", ele);
    for (let i = 0; i < plt_time.length; i++) {
      if (plt_time[i] < arrival) {
        plt_time[i] = departure;
        got_platform = true;
        break;
      }
    }

    if (!got_platform) plt_time.push(departure);
  }

  // console.log(" plt-time: ", plt_time);

  return plt_time.length;
}

let arr_string = "2148 2334 338 25 2121 2353 1125 2358 1023";
let dep_string = "2238 2349 1518 939 2147 2355 2233 2359 2200";

let arr = arr_string.split(" ").map((ele) => +ele);
let dep = dep_string.split(" ").map((ele) => +ele);

console.log("minimum number of stations: ", findPlatform(arr, dep));
