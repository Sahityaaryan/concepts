// DP in two loop structure

function coinChange1(coins: number[], amount: number): number {
  const dp = Array(amount + 1).fill(Infinity);
  dp[0] = 0;

  for (let coin of coins) {
    for (let i = coin; i <= amount; i++) {
      if (dp[i - coin] !== Infinity) {
        dp[i] = Math.min(dp[i - coin] + 1, dp[i]); // here the "+ 1" is because we are adding the coin of the value "coin" in the total number of coins required (which is logical!!!)

        // it's just doing that if we add
        // the coin of amount "coin" to make the "i" amount will it require the less
        // number of coins than the "i" amount requires now? if yes then we change
        // the value of dp[i] because ultimate work of dp is to store the minimum
        // number of coins required to make the ith amount
        //
        // Just the game is we are checking the minimum number of coins required for
        // every amount between the "coin" and the target "amount".
      }
    }
  }

  return dp[amount] !== Infinity ? dp[amount] : -1;
}

// T.C : O(N * (the distance between the lowest value present in the array to the target amount))
// S.C : O(amount)
//

// *********************** Recursive approach
//
//
// In this given approach still we are doing the same thing we are filling the dp which
// where dp[i] is the minimum number of required coins to make the "i" amount and we
// are doing this recursively we are saying that if you want to check what is the
// minimum number of coins required to form the sum then first tell me what is the
// minimum number of coins required to form the sum - coin and then we will talk
//

function min_coins_required(
  coins: number[],
  sum: number,
  dp: number[],
): number {
  if (sum == 0) return 0;
  if (sum < 0) return Number.MAX_SAFE_INTEGER;
  if (dp[sum] != -1) return dp[sum];

  let final_req_coins = Number.MAX_SAFE_INTEGER;

  for (let coin of coins) {
    let req_coins = min_coins_required(coins, sum - coin, dp);

    if (
      req_coins != Number.MAX_SAFE_INTEGER &&
      final_req_coins > req_coins + 1
    ) {
      final_req_coins = req_coins + 1;
    }
  }

  return (dp[sum] = final_req_coins);
}

function coinChange(coins: number[], amount: number): number {
  let dp: Array<number> = new Array(amount + 1).fill(-1);
  let required_coins = min_coins_required(coins, amount, dp);

  return required_coins != Number.MAX_SAFE_INTEGER ? required_coins : -1;
}

// T.C : O(N^(till the sum isn't decreased to 0 or less than it after being substracted by the amount of coins given
// in the array))
//

// why the iterative approach if more better than the recursive approach ?
//
// Because
// In the Recursive approach:->  the T.C of the recursive approach is changing exponentialy O(N^(till the sum isn't decreased to 0 or less than it after being substracted by the amount of coins given
// in the array))
// In the iterative approach :-> the T.C is (O(N * (the distance between the lowest value present in the array to the target amount)))
