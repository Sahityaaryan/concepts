

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;


#define pb push_back
#define vi vector<int>
#define vvi vector<vector<int>>
#define vvvi vector<vector<vector<int>>>
#define pii pair<int, int>
#define all(x) x.begin(), x.end()
#define sz(x) (int)x.size()
#define ll long long
#define F first
#define S second
#define ln(s) (int)s.length()
#define umci unordered_map<char, int>
#define umii unordered_map<int, int>
#define umsi unordered_map<string, int>

/**
 * Solved
 *
 * link:-> https://cses.fi/problemset/task/2220/
 *
 *
 * here this question belongs to right choice of the dp states
 *
 * and the right state is that which can uniquely identify every situation
 *
 *
 */


ll dp[20][2][10][2];

int sol(int idx, bool tight ,bool has_leading_zero ,int prev ,string& str){

    if(idx == ln(str)) return 1;
    if(dp[idx][tight][prev][has_leading_zero] != -1) return dp[idx][tight][prev][has_leading_zero];

    int limit = tight ? str[idx] - '0': 9;
    int ans = 0;

    for(int num=0; num <= limit; ++num){
        bool newTight = tight && (num == limit);

        if(!has_leading_zero && num == prev) continue;
        else ans += sol(idx+1, newTight, has_leading_zero && (num == 0), num,str);
    }

    return dp[idx][tight][prev][has_leading_zero] = ans;
}


int main(){

   long int t;
    cin>> t;

    while(t--){
        ll l,r;

        cin >> l>> r;
        memset(dp, -1, sizeof(dp));
        string str;
        ll num1 = 0;
        // if(l != 1){
        str = to_string(l-1);
        // cout << "str: " << str << endl;
        num1 = sol(0,1,1,0,str);
        // }

        // cout << "\nnum1: " << num1 << endl;


        memset(dp, -1, sizeof(dp));
        str = to_string(r);
        ll num2 = sol(0,1,1,0,str);
        // cout << "\n num2: " << num2 << endl;
        // cout << num2 << ' ' << num1 << endl;
        cout << num2 - num1 << endl;
    }

return 0;
}


// g++ 11.cpp -o t && ./t
