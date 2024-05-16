#include<bits/stdc++.h>
using namespace std;
    string largestOddNumber(string num) {
        int i = 0;
        string ans = "";
        
        while(i < num.length()){

            if((num[i]-'0') % 2 != 0){
                string ans = "";
                ans += num[i];
                return ans;
            }
            i++;
        }

        return "";
    }

int main()
{
    // cout << largestOddNumber("52");

    string str = "JaiMataDI";

    cout << str.substr(0,0);
    
    cout << endl;
    return 0;
}