#include<bits/stdc++.h>
using namespace std;


// this can also be done with method of (subarray(count == goal) - subarray(count == goal-1))

// But why do we use these methods and when to use these methods

// * when to use this method :-> 1. subarray problem where you have to find the subarray following a particular conditions,
// Subarrays staisfying can be different some subarray you will get by multiplication of some logical number generated through observations or just by following n*(n+1)/2 (or sum of the increasing window) approach, and this is the point where you should use this method.



// Here in these code I have done something similar and later i have applied the above known concept
   int numSubarraysWithSum(vector<int>& nums, int goal) {
        
        int lead = 0, lag = 0, total = 0, tempSum = 0, cnt = 0, n = nums.size();


        if(goal == 0){ // calculating by normal subarray count find formula (n*(n+1))/2 (n = size of subarray)

            while(lead < n){

                if(nums[lead] == 0){
                    cnt++;
                } else {
                    total += (cnt*(cnt+1))/2;
                    cnt = 0;
                }
                lead++;
            }

            if(cnt > 0){
                total += (cnt*(cnt+1))/2;
            }

            return total;
        }


        //counting subarrays staisfying can be different some subarray you will get by multiplication of some logical number generated through observations

        while(lead < n){
            

             if (tempSum + nums[lead] > goal){

                while(tempSum == goal && lag < n){
                    total += cnt;

                    // cout << "cnt: " << cnt << endl;
                    tempSum -= nums[lag];
                    lag++;
                }

                cnt = 0;
            }
            tempSum += nums[lead];

            if(tempSum == goal){
                cnt++;
            }

            lead++;
        }

        // cnt = 1;

        if(tempSum == goal){
            
            if(cnt == 0){
                cnt = 1; // not always good
            }
            while(tempSum == goal && lag < n){
                    total += cnt;
                    // cout << "cnt: " << cnt << endl;
                    tempSum -= nums[lag];
                    lag++;
                }
        }

        return total;

    }


// Optiimized way of solving this question: using find subarray count satisfying the less than or equal to the necessary condition

    int countSubarrayGoalLessThanOrEqualTo(vector<int> &nums, int goal)
    {

        if (goal < 0)
        {
            return 0;
        }

        int lead = 0, lag = 0, ans = 0, window = 0, n = nums.size(), tempSum = 0, total = 0;

        while (lead < n)
        {

            tempSum += nums[lead];

            while (tempSum > goal && lag <= lead)
            {
                tempSum -= nums[lag];
                lag++;
            }

            total += lead - lag + 1;
            lead++;
        }

        return total;
    }

    int numSubarraysWithSum(vector<int> &nums, int goal)
    {
        return (countSubarrayGoalLessThanOrEqualTo(nums, goal) - countSubarrayGoalLessThanOrEqualTo(nums, goal - 1));
    }


    // ---- Another miscellaneous way

 int numSubarraysWithSum(vector<int>& nums, int goal) {
        unordered_map<int, int> count;
        count[0] = 1;
        int curr_sum = 0;
        int total_subarrays = 0;

        // what would be the logic and though behind this method 

        // which principle is it based upon, and how can I know when to use this?

        for (int num : nums) {
            curr_sum += num;
            if (count.find(curr_sum - goal) != count.end()) { // why this is working because if we reduce those count[curr_sum-goal] subarrays from the current subarray then the resulting subarrays
            // has the same sum suppose from [1, 0, 1, 0, 1] we got two subarray like => [0,1,0,1] + [1,0,1] so what we have reduced in these subarrays [1] and [1,0] subarrays which counts to the 
            // curr_sum(3) - goal(2) == 1
                total_subarrays += count[curr_sum - goal];
            }
            count[curr_sum]++;
        }

        return total_subarrays;
    }


    // ------ Prefix Sum

int main(){
    
 cout << endl;
return 0;
}


/** 

The code snippet you provided is an implementation of the prefix sum technique combined with a hash map (or unordered map in C++) to efficiently count the number of subarrays that sum to a given target (goal). This approach is particularly useful for problems involving *******subarray sums********  and is based on the following principles:
Key Concepts:

    Prefix Sum: The prefix sum is a running total of the elements in an array. By maintaining a cumulative sum (curr_sum), you can determine the sum of any subarray by subtracting two prefix sums.

    Hash Map for Counting: The unordered map (count) is used to store the frequency of each prefix sum encountered so far. This allows for quick lookups to see how many times a particular sum has occurred.

    Subarray Sum Condition: The condition curr_sum - goal checks if there exists a previous prefix sum that, when subtracted from the current prefix sum, equals the target sum (goal). If it does, it means there is a subarray that sums to goal.

Logic Behind the Method:

    Initialization: Start by initializing the count of prefix sums with count[0] = 1, which accounts for the case where a subarray starting from the beginning of the array sums to goal.

    Iterate Through the Array: For each element in the array:
        Update the curr_sum by adding the current element.
        Check if curr_sum - goal exists in the count map. If it does, it means there are one or more subarrays that sum to goal, and you can add the count of those occurrences to total_subarrays.
        Update the count of the current prefix sum in the map.

When to Use This Approach:

    Subarray Sum Problems: This technique is particularly useful for problems where you need to find the number of subarrays that sum to a specific value, as it reduces the time complexity significantly compared to a naive approach.

    Dynamic Programming: It can also be seen as a dynamic programming approach where you are building up solutions (counts of subarrays) based on previously computed results (prefix sums).

Time Complexity:

    The time complexity of this approach is O(n), where n is the number of elements in the input array nums, because you are iterating through the array once and performing constant-time operations (insertions and lookups) in the hash map.
**/