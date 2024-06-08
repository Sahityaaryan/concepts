#include<bits/stdc++.h>
using namespace std;


void printArray(vector<int>arr){
    cout << "\narray:\n";
    for(auto it:arr){
        cout << it << ' ';
    }
    cout << endl;
}

// ! problem: it is not handling the first index case for ; "babad"; "


// string preProcessing(string s){
//     int i = 0;
//     string ans = "";

//     while(i < s.length()){
//         ans  += '#';
//         ans += s[i];
//         i++;
//     }
//     ans += '#';
//     return ans;
// }

// string longestPalindrome(string s){

//     string prevString = s;


//     int lengthOfLongestSubstring = 0, startingIndexOfLongestSubstring =1, i = 1,l = 1, r=1;;

//     s = preProcessing(s);

//     int n = s.length();
//     vector<int> p(n,0);
    
//     while(i < n-1){
        
//         // check if the has crossed the boundary of the longest palindrome found then initialize the p[i] to zero and if it is inside the
//         // boundary of the longest palindrome  then it is possible that if we take the center of that palindrome and will see that there
//         // are some subpalindromes within that longest palindrome so why to check for those position which we already know are 
//         // forming palindromes 
        
//         p[i] = max(0,min(r-i,p[(r - (i-l))])); // here l and r are the boundary pointers for the longest palindrome and l+r-i will give the mirror
//         //  position of i in the palindromic string

//         while((i-p[i]) >= 0 && (i+p[i]) < n  && s[i+p[i]] == s[i - p[i]]){
//             // cout << "target: " << s[i-p[i]]  << " index: " << i-p[i]<< endl;
//             p[i]++;
//         }
// I want to know if there are any dues at the library with my identity card with roll number 2204013, Ece department.
//             // cout << "i: "<< i << " p[i]: " << p[i] << endl;

//         if(i + p[i] > r){
//             l = i-p[i];
//             r = i + p[i];
//         }
        
//         if(lengthOfLongestSubstring < (p[i]-1)){
//             lengthOfLongestSubstring = p[i] - 1;
//             startingIndexOfLongestSubstring = i;
//         }

//         i++;
//     }

//     // if even length palindromic string

//     int startingIndexInOriginalString;

//     if(lengthOfLongestSubstring % 2 == 0){
//         startingIndexOfLongestSubstring--;
//         startingIndexInOriginalString = (startingIndexOfLongestSubstring - 1)/2;
//         startingIndexInOriginalString = (startingIndexInOriginalString - (lengthOfLongestSubstring/2) + 1);   
//     } else {
//         startingIndexInOriginalString = (startingIndexOfLongestSubstring - 1)/2;
//         startingIndexInOriginalString = startingIndexInOriginalString - (lengthOfLongestSubstring/2);       
//     }


//     return (prevString.substr(startingIndexInOriginalString, lengthOfLongestSubstring));  

// }


string preprocess(string s){
    int n = s.length();
    for(int i=0;i<=2*n;i+=2)
    {
        s.insert(i,"#");
    }
  return s;
}


    string longestPalindrome(string s){
        int C=0,R=0;
        string original = s;
        s = preprocess(s);
        int n = s.length();
        vector<int> P(n,0);
        int maxCenter=0,maxLen=0;
        for(int i=0;i<n;i++){
                
            int i_mirror = 2*C-i;
            if(i<R){ // this condition is just to avoid array index overflow && also checking whether the index is in the range or not
                P[i] = min(P[i_mirror],R-i);
            }
            int left = i-(P[i]+1);
            int right = i+(P[i]+1);
            while(left>=0 && right<n && s[left]==s[right]){
                P[i]++;
                left--;
                right++;
            }
            if(i+P[i]>R)
            {
                C=i;
                R=i+P[i];
            }

            cout << "c: "<<C<< " R: " << R << endl;
            if (P[i] > maxLen) {
            maxLen = P[i];
            maxCenter = i;
        }
        }

        printArray(P);
        int start = (maxCenter - maxLen) / 2;
        return original.substr(start, maxLen);
    }



int main()
{
    string s = "babadada";

    cout << "ans: " << longestPalindrome(s) << endl;
    
    cout << endl;
    return 0;
}







