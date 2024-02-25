

#include<bits/stdc++.h>
using namespace std;


string sortLexical(string s)
{
    
    int i = 0,maxIndex;
    int hsh[26];
    string ans = "";

    fill(hsh,hsh+26,0);

    while(i < s.size())
    {
        hsh[s[i]-'a']++;
        maxIndex = max(maxIndex,s[i]-'a');
        
        i++;
    }

    i = 0;

    while(i <= maxIndex)
    {
        if(hsh[i] > 0) {
            while(hsh[i])
            {
                ans = ans + (char)(i+97);
                hsh[i]--;
            }
        }
        i++;
    }

    return ans;

}


int main()
{
string s = "codingwallah";
string ans =  sortLexical(s);
    cout << ans;

    cout << endl;
    return 0;
}
