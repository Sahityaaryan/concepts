#include<bits/stdc++.h>
using namespace std;




// more optimal and correct approach

 int numberOfSubstrings(string s) {
       int lastseen[3]={-1,-1,-1};
       int cout=0;
        for(int i=0;i<s.size();i++){
            lastseen[s[i]-'a']=i;
            if(lastseen[0]!=-1&&lastseen[1]!=-1&&lastseen[2]!=-1)
            cout+=1+min(lastseen[0],min(lastseen[1],lastseen[2]));
        }
        return cout;
    }

int main(){
    
 cout << endl;
return 0;
}