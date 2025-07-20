#include<bits/stdc++.h>
using namespace std;

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

/**
 *
 * 3490 (leetcode) :-> https://leetcode.com/problems/count-beautiful-numbers/
 *  Thank you gpt :)
 *
 * This Method of dp is totally illegal to use like it can smash all the memory limit exceed
 *
 * What should be your possible states for the dp?
 * -> whatever which can uniquely identfies each and every case
 *
 *
 */




class Solution {
public:
    unordered_map<string, int> dp;
    int sol(int idx, bool tight,int pr ,int sum,bool has_leading_zero ,string& str){

        if(idx == sz(str)) return ((sum > 0) && (pr%sum == 0));
        string key = to_string(idx)+'-'+ to_string(tight)+'-'+to_string(pr)+'-'+to_string(sum)+'-'+to_string(has_leading_zero);

        if(dp.find(key) != dp.end()) return dp[key];

        int limit = tight ?  str[idx]-'0':9;
        int ans = 0;

        for(int num =0; num <= limit; ++num){
            bool newTight = tight && (num == limit);
            int newSum = sum + num;

            if(num == 0 && has_leading_zero){
                ans += sol(idx+1, newTight, 1 , newSum, 1, str);
                continue;
            }
            int newPr = (pr*num);
            ans += sol(idx+1, newTight, newPr , newSum, 0, str);
        }
        return  dp[key] = ans;
    }

    int beautifulNumbers(int l, int r) {


       string s = to_string(l-1);
       int num1 = sol(0,1,1,0,1,s);

       dp.clear();
        s = to_string(r);
        int num2 = sol(0,1,1,0,1,s);

        return num2-num1;
    }
};

int main(){


    Solution a;

    cout << "Jai Mata Di";
    return 0;

    int l,r;
    cin >> l >> r;
    cout << endl;
    cout << a.beautifulNumbers(l, r);


    return 0;
}
