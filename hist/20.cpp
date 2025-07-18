#include<bits/stdc++.h>
using namespace std;

/**
 * 1. Horizontal Scanning
 * Now this solution is actually checking and reducing the prefix to make it match
 *
 * (string) find: In C++, string find() is a built-in library function used to find the first occurrence of a substring in the given string, and if
 * it's not found then it returns a number a larger than the length of the string on which we are searching.
 *
 */

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.size() == 0) return "";
        string prefix = strs[0];
        for (int i = 1; i < strs.size(); i++)
            while (strs[i].find(prefix) != 0) { // != 0 because we want matching "prefix" and prefix starts from 0
                prefix = prefix.substr(0, prefix.length() - 1); // reducing the string by one character if it's not matching
                if (prefix.empty()) return "";
            }
        return prefix;
    }
};

/**
 * 2. Vertical Scanning
 *
 * here you just take ith character of hte str[0] and check whether it's matching with the ith character of the remaining strings
 * and decrease your answer accordingly
 *
 */

class Solution2 {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) return "";
        for (int i = 0; i < strs[0].size(); i++) {
            char c = strs[0][i];
            for (int j = 1; j < strs.size(); j++) {
                if (i == strs[j].size() || strs[j][i] != c)
                    return strs[0].substr(0, i);
            }
        }
        return strs[0];
    }
};

/*
 * Divide and Conquer approach
 *
 * here we are checking what the longest common prefix in the strings in  the string array from index l to r
 *
 * and onece we divide by string with this method then we check the minimum matching prefix from the both division
 *
 *
 */

 class Solution3 {
 public:
     string longestCommonPrefix(vector<string>& strs) {
         if (strs.empty()) return "";
         return longestCommonPrefix(strs, 0, strs.size() - 1);
     }

 private:
     string longestCommonPrefix(vector<string>& strs, int l, int r) {
         if (l == r) {
             return strs[l];
         } else {
             int mid = (l + r) / 2;
             string lcpLeft = longestCommonPrefix(strs, l, mid);
             string lcpRight = longestCommonPrefix(strs, mid + 1, r);
             return commonPrefix(lcpLeft, lcpRight);
         }
     }

     string commonPrefix(string left, string right) {
         int min = std::min(left.length(), right.length());
         for (int i = 0; i < min; i++) {
             if (left[i] != right[i]) return left.substr(0, i);
         }
         return left.substr(0, min);
     }
 };


 /**
  * 4. Binary search on answer: here our answer is in the sorted order like the longest common prefix will be either 0 or minimum length (among all the string)
  * so we can do binary search on answer here
  */

  class Solution4 {
  public:
      string longestCommonPrefix(vector<string>& strs) {
          if (strs.empty()) return "";
          int minLen = INT_MAX;
          for (string str : strs) minLen = min(minLen, (int)str.length());
          int low = 0;
          int high = minLen;
          while (low <= high) {
              int middle = (low + high) / 2;
              if (isCommonPrefix(strs, middle))
                  low = middle + 1;
              else
                  high = middle - 1;
          }
          return strs[0].substr(0, high);
      }

  private:
      bool isCommonPrefix(vector<string>& strs, int len) {
          string str1 = strs[0].substr(0, len);
          for (int i = 1; i < strs.size(); i++)
              if (strs[i].find(str1) != 0) return false;
          return true;
      }
  };

int main(){

    return 0;
}
