// https://codeforces.com/problemset/problem/1326/c

#include<bits/stdc++.h>
using namespace std;
#define ll long long
// void p(vector<int> &ans);

void printArray(vector<int> v)
{
    int i=0;

    cout << "\nPrinting array: ";
    while(i < v.size())
    {
        cout << v[i++] << ' ';
    }
    cout << '\n';
}

void sir()
{
    int n,k;

    cin >> n>> k;
     int M = 998244353;

    vector<int> a(n);

    for(int i=0;i <n;i++) cin >> a[i];
    
       
        vector<int> b;

        ll total = 0;
        int x = n;
        int cc = 0;
        while(1)
        {
            total += x;
            x--;
            cc++;
            if(cc >= k) break;
        }

        int other = n-k+1;

        for(int i=0;i<n;i++)
        {
            if(a[i]>=other)
            {
                b.push_back(i);
            }
        }

        cout << "\nbefore";
        printArray(b); 
        sort(b.begin(),b.end());

      cout << "\nAfter";
        printArray(b); 

        ll total_ways=1;

        for(int i=0;i < (int)b.size()-1;i++)
        {
            total_ways= ((total_ways%M) * ((ll)(b[i+1]-b[i]))%M)%M;
        }

        cout << total << ' ' << total_ways;
    
}

int main(){
    
    sir();


    cout << endl;
    return 0;
}

//7 3 2 7 3 1 5 4 6
