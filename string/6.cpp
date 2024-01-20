#include<bits/stdc++.h>
using namespace std;


// * it is easy but I didn't get it.

       string convert(string s, int numRows) {
    
    if(numRows <= 1) return s;

    int i =0, j = 0, n=s.length(), dir = -1;

    vector<string> v(numRows,"");

    while(i < n)
    {
        if( j== numRows-1 || j==0)  dir*=-1;

        v[j] += s[i++];

        if(dir==1) j++;
        else j--;
    }

    string ans;

    for(auto it:v)
    {
        ans+=it;
    }

    return ans;

    }

int main()
{

 
string s = "PAYPALISHIRING";

    cout << convert(s,3);
    cout << endl;
    return 0;
}