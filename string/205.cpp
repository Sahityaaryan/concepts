#include<bits/stdc++.h>
using namespace std;
int main()
{
 
    string s = "Hello, world";
    string t = "elppk hkrpb";
    unordered_map<char,char> mp;

    int i = 0;

    while(i < s.length()){
        cout <<(int) mp[s[i]] << endl;
        char g = ' ';
        if(mp[s[i]]==g){
            cout << "got it\n";
        }
        i++;
    }


    

    cout << endl;
    return 0;
}