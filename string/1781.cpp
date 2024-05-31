#include <bits/stdc++.h>
using namespace std;

int calculateBeauty(string s, int start, int end)
{

    unordered_map<char, int> mp;

    int lo = INT_MAX, hi = INT_MIN;

    while (start <= end){
        mp[s[start++]]++;
    }

    if (mp.size() == 1)
        return 0;

    for (auto it : mp){
        // cout << "second: " <<it.second << endl;
        lo = min(lo, it.second);
        hi = max(hi, it.second);
    }

    if(hi == INT_MIN || lo == INT_MAX) return 0;

    // cout << "hi: " << hi  << " lo: " << lo << endl;

    return hi - lo;
}

int beautySum(string s){
    int lagger = 0, leader = 0, beauty, count = 0;

    while(leader < s.length()){
        
    }
    return count;
}

 

int main()
{
    string s = "aba";


    // vector<string> ans = substrings(s);
    // cout << "len: " << ans.size() << endl;

    // s = "aabcb";
    //  ans = substrings(s);
    // cout << "len: " << ans.size() << endl;

    s = "aabcbaa";
    //  ans = substrings(s);
    // cout << "len: " << ans.size() << endl;
    
    // cout << "substrings: " << endl;


    cout << " ans: " << beautySum(s) << endl;
    // for (auto it : ans)
    // {
    //     cout << it << " ";
    // }

    // cout << "beauty: " << calculateBeauty("ab",0,1) << endl;

    cout << endl;
    return 0;
}

// ab , abc,bc, cb  = 1

// a aa a, ab ,abc , b , bc, c , cb, cba b ,ba, a , aa ,a


