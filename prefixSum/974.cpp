#include <bits/stdc++.h>
using namespace std;

int subarraysDivByK(vector<int> &nums, int k)
{

    /*
            ***APPROACH***

 As stated previously, our task is to determine the number of pairs (i, j) where i < j and (prefixSum[j] - prefix[i]) % k = 0. This
 equality can only be true if prefixSum[i] % k = prefixSum[j] % k. We will demonstrate this property.

We can express any number as number = divisor × quotient + remainder. For example, 13 when divided by 3 can be written as 13 = 3 * 4 + 1.
So we can express:
a) prefixSum[i] as prefixSum[i] = A * k + R0 where A is the quotient and R0 is the remainder when divided by k.
b) Similarly, prefixSum[j] = B * k + R1 where B is the quotient and R1 is the remainder when divided by k.

We can write, prefixSum[j] - prefixSum[i] = k * (B - A) + (R1 - R0). The first term (k * (B - A)) is divisible by k, so for the entire
expression to be divisible by k, R1 - R0 must also be divisible by k. This gives us an equation R1 - R0 = C * k,
 where C is some integer. Rearranging it yields R1 = C * k + R0. Because the values of R0 and R1 will be between 0 and k - 1, R1 cannot
  be greater than k. So the only possible value for C is 0, leading to R0 = R1, which proves the above property. If C > 0, then the RHS would
   be at least k, but as stated the LHS (R1) is between 0 and k - 1.

   But here is a game suppose a number 7 and 8 and we have to check whether the sum of them is divisible by 5 or not so:
   1. 7+8 == 15 (divisible by 5)
   2. as (a + b) % 5 == a%5 + b%5, so in our case prefixMod is always a%5 just we have to put the new one (nums[i]) to modulo

   And we are adding k as well, just inorder to handle the negative integers
    */

    int n = nums.size();
    int i = 0, count = 0;
    int prefixMod = 0;
    vector<int> modGroups(k + 1);

    modGroups[0] = 1;

    while (i < n)
    {
        prefixMod = ((prefixMod + (nums[i] % k)) + k) % k;
        count += modGroups[prefixMod];
        modGroups[prefixMod]++;
        i++;
    }

    return count;
}

int main(){

    vector<int> nums = {4, 5, 0, -2, -3, 1};
    int k = 5;

    cout << "\n Ans: " << subarraysDivByK(nums, k) << endl;
    cout << endl;
    return 0;
}
