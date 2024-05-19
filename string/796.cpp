#include<bits/stdc++.h>
using namespace std;

    bool matchPattern(string s,string goal, bool found, vector<int> &position){

        if(!position.size() && !found){
            return found;
        }

        int i = position[position.size()-1], j = 0;

        while(j < goal.length()){
            
            i %= s.length(); 

            if(s[i]!=goal[j]){
                position.pop_back();
                return matchPattern(s,goal,false,position);
            }
            i++;
            j++;
        }

        return true;
    }
    bool rotateString(string s, string goal) {

// it is having the issue of duplicacy finding 
        int i =0,j = 0;

        // first check: same size

        if(s.length() != goal.length()){
            return false;
        }

        // second check: same order of elements

        unordered_map<char,vector<int>> mp;

        while(i < s.length()){
            mp[s[i]].emplace_back(i);
            i++;
        }


        return matchPattern(s,goal,false,mp[goal[0]]);
        
    }

int main()
{
 
    vector<int>v = {1,2,3};


    for(auto i:v){
        cout << i << " ";
    }
    cout << endl;
    return 0;
}