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

