#include<bits/stdc++.h>
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


using namespace std;


/**
 *
 * Topic :-> Digit Dp
 *
 * G-one numbers (SPOJ) :-> https://www.spoj.com/problems/GONE/
 *
 */


int dp[20][3][73];

// sieve of erastothenes (sieve till roots)

bool isPrime(int n){
    if(n < 2) return 0;
    if(n == 2 || n == 3) return 1;
    vector<bool> is_prime(n+1,1);
    is_prime[0] = is_prime[1] = 0;

    for(int i = 2; i <= n; ++i){
        if(is_prime[i]){
            for(int j = i*i; j <= n; j+=i){
                is_prime[j] = 0;
                if(!is_prime[n]) return false;
            }
        }
    }
    return true;
}

int sol(int idx, bool tight, int sum, string& str){
    if(idx >= str.length()) return isPrime(sum);
    if(dp[idx][tight][sum] != -1) return dp[idx][tight][sum];

    int limit = tight ? str[idx] - '0': 9;
    int ans = 0;
    for(int num=0; num <= limit; ++num){
        int newSum = sum + num;
        bool newTight = tight && (num == limit);
        ans += sol(idx+1, newTight, newSum, str);
    }

    return dp[idx][tight][sum] = ans;
}


int main(){

    int t;
    cin>> t;

    while(t--){
        ll l,r;

        cin >> l>> r;
        memset(dp, -1, sizeof(dp));
        string str = to_string(l-1);
        ll num1 = sol(0,1,0,str);
        memset(dp, -1, sizeof(dp));
        str = to_string(r);
        ll num2 = sol(0,1,0,str);
        cout << num2 - num1 << endl;
    }

return 0;
}


// g++ 10.cpp -o t && ./t


/*
 *
 *
 * 3
 10 19
 1 9
 20 29

 */
