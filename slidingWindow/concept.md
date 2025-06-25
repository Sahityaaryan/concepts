

# identification
- should be a question of array or string
- they should be talking about the array or substring
- or given a number k(window size) and given some condition to find appropriate substring or sub array
- or etiher given what is appropriate substring and subarray or condtions and you have to calculate the window size


# Understanding Pattern
 1. **Detecting anagrams**:
    - Create a map on the target string
    - Use that map by reducing the frequency of a char in the previous step and after some logical condition (like if you are searching for anagrams so the window size must be equal to the length of the target string) you can check whether the frequency of all the chars of the target string is zero or not.
    - If (zero) then you have found one anagram
    - Example: `https://leetcode.com/problems/find-all-anagrams-in-a-string/description/` check the recent submission of this.


2. **Basic Sliding Window Template** : Searching the maximum/minimum length subarray which satisfies a particular condition

    - Example: `https://leetcode.com/problems/minimum-size-subarray-sum/` or `https://www.geeksforgeeks.org/problems/first-negative-integer-in-every-window-of-size-k3345/1`

3. **Subarrays** : In questions including the subarray you need to undersatnd that how the subarray is forming and you need to just revise the
different variety of formation of subarrays through your code.

- 1. https://leetcode.com/problems/find-the-number-of-subarrays-where-boundary-elements-are-maximum/description/ : This is just normal
- 2.https://leetcode.com/problems/count-subarrays-with-fixed-bounds/description/ : This is a good one
