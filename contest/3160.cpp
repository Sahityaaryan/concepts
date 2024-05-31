#include<bits/stdc++.h>
using namespace std;

    vector<int> queryResults(int limit, vector<vector<int>>& queries) {

        
        unordered_map<int,int> ballColor;
        vector<int> ans;
        
        int i = 0,count = 0;
        while(i < queries.size()){

           ballColor[queries[i][0]] = queries[i][1];
           unordered_map<int,int> frequencyArray;

           for(auto it:ballColor){
             frequencyArray[it.second]++;
           }

           count  = frequencyArray.size();

           ans.push_back(count);
           
            i++;
        }
        
        return ans;
        
    }

int main()
{
 
    
    cout << endl;
    return 0;
}