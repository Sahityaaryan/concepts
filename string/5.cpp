#include <bits/stdc++.h>
using namespace std;
bool isPalin(string s, int l, int r){
    bool flag = true;
    int i = 0;
    while (i <= ((r - l + 1) / 2))
    {
        if (s[l + i] != s[r - i])
        {
            flag = false;
            break;
        }
        i++;
    }
    return flag;
}

string longestPalindrome(string s)
{
    if(!(s.length()-1)){
        return s;
    }

    if(isPalin(s,0,s.length()-1)){
        return s;
    }

    int leader = 0, width = 0;
    int lagger = 0;

    vector<int> ans(1001);
    int n = s.length();

    while (lagger < n){

        if(leader == n){
            lagger++;
            leader = lagger;
        }

        if (s[leader] == s[lagger])
        {
            if (isPalin(s, lagger, leader) && leader != lagger)
            {
                // cout << "lagger: "<< lagger  << " leader: " << leader << endl;

                if(width < leader-lagger+1){
                width =  leader - lagger + 1;
                ans[width] = lagger;
                }
            }

            if (leader != lagger)
                lagger++;
        }
        leader++;
    }
 

    if(!ans[width] && !width){
        return s.substr(0,1);
    }
    
    // cout << "width: " << width  << "lagger: " << ans[width]<< endl;
    return s.substr(ans[width], width);
}

int main()
{
    string s = "cbbd";
    // cout << longestPalindrome(s) << endl;
    // cout << endl;
    s = "babad";
    s = "aacabdkacaa";
    cout << longestPalindrome(s) << endl;
    // cout << endl;

    cout << endl;
    return 0;
}