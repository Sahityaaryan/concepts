#include <bits/stdc++.h>
using namespace std;

    int calculateBeauty(unordered_map<char, int> mp) {
        int lo = INT_MAX, hi = INT_MIN;
        for (auto it : mp) {
            // cout << it.first << " " << it.second << endl;
            if (it.second) {
                lo = min(lo, it.second);
                hi = max(hi, it.second);
            }
        }
        if (hi == INT_MIN || lo == INT_MAX)
            return 0;
        return hi - lo;
    }

    // memoization : failed
    int beautySum(string s) {

        int i = 0, j = 0, lagger = 0, beauty = 0,hi,lo;

        while(i < s.length()-1){
            j = i;
            lo = INT_MAX,hi = INT_MIN;
            vector<int> freq(26,0);

            while(j < s.length()){
                freq[s[i]-'a']++;
                hi = max(hi,freq[s[i]-'a']);
                lo = min(lo, freq[s[i]-'a']);
                beauty += (hi-lo);
                j++;
            }
            i++;
        }

        return beauty;
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


