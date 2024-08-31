#include<bits/stdc++.h>
using namespace std;

string trim(string& s){

    int i = 0;

    while( i < s.length() && s[i] == ' '){
        i++;
    }

    int j = i;
    i = s.length()-1;

    while(i >= 0 && s[i] == ' ') {
        i--;
    }

    return s.substr(j,i-j+1);
}


string reverseWords(string s) {

string ans = "";

int n = s.length(), end = n-1;

for(int i = n-1; i >= 0; i--){

       while( i >= 0 && s[i] == ' '){
           i--;
       }

       end = i;

       while( i >= 0 && s[i] != ' '){
           i--;
       }
       
       ans += s.substr(i+1, end - i);
       ans += ' ';
}

return trim(ans);
}


int main(){
    string s = " hello world ";
    // s = "the sky is blue";
    // cout << "\n" << trim(s) << "|";

    unordered_map<int, int> mp;

    mp[2] = 0;

    cout << (int) mp[0];

    cout << '\n';
    return 0;
}
