// Problem :-> https://www.geeksforgeeks.org/problems/count-triplets-with-sum-smaller-than-x5549/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=practice_card

// code explaination
//
// I have tried my best to solve this code by using binary search but I couldn't solve this using it because this question needs more like of "dynamic subset" calculation
// like here by "k-j" we are actually taking combinations formed by constant i , constant midpoint aka j, but variable end point that is k --> [1,2, 5], [1,2, 4], [1,2,3]
// and thus by increasing j we are checking out whether the element ahead can be a possible midpoint or not? and after we have checked the possible combinations of middle point and
// the endpoint the outer list will again force us to find the combinations for varying midpoints and endpoints but this time with a different start point

// code is below:->

// function countTriplets(nums: Array<number>, n: number, target: number) {
//   nums.sort((a, b) => a - b);

//   let ans = 0;
//   for (let i = 0; i < n - 2; ++i) {
//     let [j, k] = [i + 1, n - 1];
//     while (j < k) {
//       const x = nums[i] + nums[j] + nums[k];
//       if (x < target) {
//         ans += k - j;
//         ++j;
//       } else {
//         --k;
//       }
//     }
//   }
//   return ans;
// }
