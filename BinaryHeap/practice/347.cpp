#include<bits/stdc++.h>
using namespace std;


 
int main(){

 set<pair<int, int>, greater<pair<int, int>>> v;

 vector<pair<int, int>> vec = {{5,-1}, {5,-1}, {2,3}, {3,2}, {4,1}};


vector<int> vec2 = {1,1,1,2,2,3};

map<int, int>mp;


// for(auto ele:vec){
//     v.insert(ele);
// }


for(auto ele:vec2){
    mp[ele]++;
}

map<int, int>::iterator it = mp.begin();




while(it != mp.end()){
    cout << it->first << ' ' << it->second << endl;
    it++;
}

// for(auto ele:v){
//     cout << ele.first << ' ' << ele.second << endl;
// }

 cout << endl;
return 0;
}