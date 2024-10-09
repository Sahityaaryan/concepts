#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    // worthless : 

bool check(string s, int leader, int lagger)
{

    while (leader > lagger)
    {
        if (s[leader] != s[lagger])
        {
            return false;
        }
        leader--;
        lagger++;
    }

    return true;
}

void sol(vector<vector<string>> &ans, vector<string>& temp, string& s, int index)
{

    if (index == s.length())
    {
        ans.emplace_back(temp);
        return;
    }

    int i = index;

    while(i < s.length()){

        if(check(s, i, index)){
            temp.emplace_back(s.substr(index, i - index + 1));
            sol(ans,temp,s,i+1);
            temp.pop_back();
        }
        i++;
    }
  
}

vector<vector<string>> partition(string s)
{

    // by Brute force it is going upto the T.C : O((N^3 -3(N^2) + 2N) / 2);
    // I can ease it by one multiple of N by using recursion to involve one level of iteration in the recursion stack
    vector<vector<string>> ans;
    vector<string> temp;

    sol(ans, temp, s, 0);

    return ans;
}
};

int main()
{

    
    vector<vector<string>> ans = partition("aab");

    cout << "printing:\n"; 

    for(auto it:ans){
        for(auto str:it){
            cout << str << " ";
        }
        cout << endl;
    }


    
    cout << endl;
    return 0;
}