#include<bits/stdc++.h>
using namespace std;

// Usecases of Manacher's algorithm

// 1. Detecting the longest palindromic substring

// 2. matching a pattern in string which iteself is a palindrome


void printArray(vector<int>arr){
    cout << "\narray:\n";
    for(auto it:arr){
        cout << it << ' ';
    }
    cout << endl;
}
// 12:52

string preprocess(string s){
    string ans="";

    for (auto ch:s){
        ans += '#';
        ans += ch;
    }
    return ans + '#';
}


// 13:09

string longestPalindrome (string s){
    string original = s;

     s = preprocess(s); // O(n)

     int n = s.length();

     vector<int> p(n,0); // s.c : O(2n)

     int C=0,R = 0, maxLen = 0, maxCenter = 0,i  = 0;

     // C = Palindromic center
     // R = distance between the 'C' and the last character of that palindromic string
     // i_mirror = here it just checking that what is the 'R'vof the matched palindrome

     while(i < n){

         int i_mirror = 2*C-i;

         if(i < R){ // use the precomputed only when i is within the range
             p[i] = min(p[i_mirror],R-i); // Here we did this min because we want to make the p[i] under the range like there are two possible cases

             // 1. The i_mirror is such a palindromic center that has a palindrome but of size within the range of the current plaindromic center formed by 'C' and 'R'
             // 2. or it may also have the palindrome of size greater than the range of the current plaindromic center formed by 'C' and 'R' so in this case we want the p[i] to be within range only
         }

         int left = i - (p[i]+1);
         int right = i + (p[i]+1);

         while(left>=0 && right < n && s[left]==s[right]){
             p[i]++;
             left--;
             right++;
         }

         if(i + p[i] > R){ // if the length of the newly found substring exceeds the current boundary then we will update the boundary
             C = i;
             R = i + p[i];
         }

         if (p[i] > maxLen){ // if the length of the current substring is greater than the maximum length substring found so far then we update the current substring as a new maximum lenght palindrome
             maxLen = p[i];
             maxCenter = i;
         }
         i++;
     }

     int start = (maxCenter - maxLen) /2;

     return original.substr(start,maxLen);

     // T.C : O(N)
     // S.C : O(2N)
}

int main()
{
    // string s = "babadada";

    string s = "gabbar";

    // cout << preprocess(s) << endl;

    cout << "ans: " << longestPalindrome(s) << endl;

    cout << endl;
    return 0;
}


// manacher's algorithm
