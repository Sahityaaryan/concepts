#include <bits/stdc++.h>
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

string longestPalindrome1(string s)
{
    if (!(s.length() - 1))
    {
        return s;
    }

    if (isPalin(s, 0, s.length() - 1))
    {
        return s;
    }

    int leader = 0, width = 0;
    int lagger = 0;

    vector<int> ans(1001);
    int n = s.length();

    while (lagger < n)
    {

        if (leader == n)
        {
            lagger++;
            leader = lagger;
        }

        if (s[leader] == s[lagger])
        {
            if (isPalin(s, lagger, leader) && leader != lagger)
            {
                if (width < leader - lagger + 1)
                {
                    width = leader - lagger + 1;
                    ans[width] = lagger;
                }
            }

            if (leader != lagger)
                lagger++;
        }
        leader++;
    }

    if (!ans[width] && !width)
    {
        return s.substr(0, 1);
    }

    // cout << "width: " << width  << "lagger: " << ans[width]<< endl;
    return s.substr(ans[width], width);
}


vector<int> manacher_odd(string s) {
    int n = s.size();
    s = "$" + s + "^";
    vector<int> p(n + 2); // it is the vector containing the d^odd total numbers of odd length palindrome
    int l = 1, r = 1;
    for(int i = 1; i <= n; i++) {
        p[i] = max(0, min(r - i, p[l + (r - i)])); // if i > r then automatically d^odd will be intialized to zero
        while(s[i - p[i]] == s[i + p[i]]) {
            p[i]++;
        }
        if(i + p[i] > r) {
            l = i - p[i], r = i + p[i];
        }
    }
    return vector<int>(begin(p) + 1, end(p) - 1);
}



int main()
{
    string s = "cbbd"; 
    s = "ababab";
    // cout << longestPalindrome(s) << endl;
    // cout << endl;
    // s = "babad";
    // s = "aacabdkacaa";
    // cout << longestPalindrome(s) << endl;
    vector<int> v = manacher_odd(s);

    cout << "\n Ans: \n";

    for(auto ele:v){
        cout << " " << ele ;
    }
    // cout << endl;

    cout << endl;
    return 0;
}