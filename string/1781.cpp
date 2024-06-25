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

        int i = 0, j = 0, lagger = 0, beauty = 0,hi,lo,dist_count, count=0 , n =s.length();

        while(i < n-1){
            j = i;
            lo = INT_MAX,hi = INT_MIN;
            vector<int> freq(26,0);
            
            dist_count = 0;

            cout << "\nbreak\n";

            while(j < n){

                if(!freq[s[j]-'a']){
                    dist_count++;
                }

                freq[s[j]-'a']++;

                hi = max(hi,freq[s[j]-'a']);
                lo = min(lo, freq[s[j]-'a']);

                    // count++;
                if(dist_count > 1){
                beauty += (hi-lo);
                    cout << "hi: " << hi << " lo: " << lo << " currChar: "<< s[j] <<" diff: "  << (hi-lo) << " beauty: "  << beauty <<   endl;
                } 
                j++;
            }
            i++;
        }

        // cout << "\nTotalCount\t" << count << endl;

        return beauty;
    }

int main()
{
    string s = "aabcb";

    s = "xzvfsppsjfbxdwkqe";

    cout << (s.length()*(s.length()+1))/2 << endl;

    // s = "aabc";

    cout << "answer: " << beautySum(s) << endl;

    cout << endl;
    return 0;
}