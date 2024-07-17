#include<bits/stdc++.h>
using namespace std;

void recur(int n, vector<string>& ans, string s, int open, int close){

        if(open > n || close > n){
            return;
        }

    if(open == n && close == n){
        ans.push_back(s);
        return;
    }

    if(open < close){
        return;
    }

    recur(n,ans,s+'(',open+1,close);
    recur(n,ans,s+')',open,close+1);
}

int main()
{
    vector<string> ans;

    recur(3,ans,"(",1,0);

    cout << "\nList:\n";
    for(auto i:ans){
        cout << i << endl;
    }

    cout << endl;
    return 0;
}

