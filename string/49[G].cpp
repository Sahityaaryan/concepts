#include<bits/stdc++.h>
using namespace std;

// # one of the best way to spot the anangrams in a very less TC

 vector<vector<string>> groupAnagrams(vector<string>& strs) {
            vector<vector<string>>  ans;
        
        int i = 0, j = 0;

        unordered_map<string,int>mp;

    // optimized solution

    while(i < strs.size()){
        string tempString = strs[i];
        sort(strs[i].begin(),strs[i].end());

        if(mp.find(strs[i]) != mp.end()){
            ans[mp[strs[i]]].emplace_back(tempString);
        } else{
            mp[strs[i]] = ans.size();
            ans.push_back({tempString});;
        }
        i++;
    }

        return ans;
    }

int main()
{
 
    
    cout << endl;
    return 0;
}