#include<bits/stdc++.h>
using namespace std;

  string longestCommonPrefix(vector<string>& v) {
        string ans="";
        sort(v.begin(),v.end());
        int n=v.size();
        string first=v[0],last=v[n-1];
        for(int i=0;i<min(first.size(),last.size());i++){
            if(first[i]!=last[i]){
                return ans;
            }
            ans+=first[i];
        }
        return ans;
}

int main()
{
 
    vector<string> strs = {"flower","flow","flight"};

    cout << longestCommonPrefix(strs);  
    return 0;
}