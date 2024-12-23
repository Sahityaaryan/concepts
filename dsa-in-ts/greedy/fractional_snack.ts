// Learning here I got to learn that for this question I want to sort the array such has I will get the maximum value with minimum capacity so
// for this i have to sort the array on the (value/capacity)

function fractionalknapsack(
  val: Array<number>,
  wt: Array<number>,
  capacity: number,
): number {
  let val_wt_array: Array<Array<number>> = [];
  let max_value_holded = 0;

  for (let i in val) {
    val_wt_array.push([val[i], wt[i]]);
  }

  val_wt_array.sort((a, b) => {
    let [val1, cap1] = a;
    let [val2, cap2] = b;

    return val2 / cap2 - val1 / cap1;
  });

  let i = 0;

  while (i < val_wt_array.length) {
    let temp_cap = val_wt_array[i][1];
    let value = val_wt_array[i][0];

    if (capacity > temp_cap) {
      max_value_holded += value;
      capacity -= temp_cap;
    } else {
      max_value_holded += (value / temp_cap) * capacity;
      break;
    }
    i++;
  }

  return max_value_holded;
}
