#include<bits/stdc++.h>
using namespace std;
 

 class Solution {
public:

        bool wordBreak(string s, vector<string>& wordDict) {
        vector<bool> dp(s.size() + 1, false);
        dp[0] = true;
        unordered_set<string> wordSet(wordDict.begin(), wordDict.end());

        for (int i = 1; i <= s.size(); i++) {
            for (const string& w : wordDict) {
                int start = i - w.length();
                if (start >= 0 && dp[start] && s.substr(start, w.length()) == w) {
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[s.size()];        
    }
};


bool solve(int start, int end, string s, vector<string>& wd){

    string temp = s.substr(start, start-end+1);

    if(end == s.length()-1){
        if(find(wd.begin(), wd.end(), temp) != wd.end()){
            return true;
        }

        return false;
    }

    if(find(wd.begin(), wd.end(), temp) != wd.end()){
        if(solve(end+1, end+1, s, wd)){
            return true;
        }
    }

    return solve(start,end+1, s,wd);
}

bool wordBreak(string s, vector<string>& wordDict){
    return solve(0,0, s, wordDict);
}


int main(){
    
 cout << endl;
return 0;
}