
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool isPalin(string s, int l, int r)
{
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

    int leader = 0, width = 0;
    int lagger = 0;
    int hsh[26];
    fill(hsh,hsh + 26,-1);
    // vector<pair<int,string>>
    vector<pair<int, int>> ans(1001);
    int n = s.size();

    // cout << hsh[2] << '\n';

    while (leader < n)
    {
        if (hsh[leader] >= lagger)
        {
            if (isPalin(s, hsh[leader], lagger))
            {
                width = max(width, leader - lagger + 1);
                ans[width] = pair<int, int>(leader, lagger);
            }
            lagger = hsh[leader] + 1;
        }
        hsh[leader] = leader;
        leader++;
    }

    int l = ans[width].first;
    int r = ans[width].second;

    cout <<"width: "<< width << '\n';
    string sl = "";

    cout << "l: "<<l << "r: "<< r << '\n';

    while (l <= r)
    {
        // cout << ": "<< s[l];
        sl += s[l++];
    }

    return sl;
}

int main(){

    string s ="abbba";

    cout << "\nans: "<< longestPalindrome(s);
    
    cout << endl;
    return 0;
}