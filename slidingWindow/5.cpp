
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

    bool isPalin(string s, int l, int r) {
        bool flag = true;
        int i = 0;
        while (i <= ((r - l + 1) / 2)) {
            if (s[l + i] != s[r - i]) {
                flag = false;
                break;
            }
            i++;
        }
        return flag;
    }

    string longestPalindrome(string s) {

        int leader = 0, width = 0;
        int lagger = 0;
        int hsh[26];
        fill(hsh, hsh + 26, -1);

        vector<pair<int, int>> ans(1001);
        int n = s.size();


        while (leader < n) {
            if (hsh[s[leader] - 'a'] >= lagger) {
                if (isPalin(s, lagger,leader)) 
                {
                    width = max(width, leader - lagger + 1);
                    ans[width] = pair<int, int>(leader, lagger);
                }
                lagger++;
            }
            hsh[s[leader] - 'a'] = leader;
            leader++;
        }

        int l = ans[width].first;
        int r = ans[width].second;

        // cout << l << ' ' << r << endl;

        return s.substr(l, width);
    }
int main(){

    string s ="abbcba";

    // cout << "\nans: "<< longestPalindrome(s);

    cout << isPalin(s, 0, s.length()-1);
    
    cout << endl;
    return 0;
}