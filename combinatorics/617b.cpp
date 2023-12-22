#include<bits/stdc++.h>
using namespace std;
#define ll long long


void solve()
{
    int n,i=0,M = 998244353,size;

    cin >> n;

    vector<int> a(n);

    while(i<n) cin >> a[i++];

    vector<int> b;
    i = 0;
    while(i<n)
    {
        if(a[i]==1) b.push_back(i);
        i++;
    }

    size = b.size();

    if(size==0)
    {
        cout << 0;
        return;
    }

    if(size==1)
    {
        cout << 1;
        return;
    }    

    sort(b.begin(),b.end());

    i = 0;

    ll total_ways=1;

    while(i<size-1)
    {
        total_ways  = ((total_ways) * (b[i+1]-b[i]));
        i++;
    }

    cout << total_ways;
    return;
}

int main()
{
    solve();
    cout << '\n';
    return 0;
}



// https://codeforces.com/problemset/problem/617/b