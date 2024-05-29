#include<bits/stdc++.h>
using namespace std;

      bool isPalin(string s, int l, int r) {
        bool flag = true;
        int i = 0;
        while (i <= ((r - l + 1) / 2)) {
            if (s[l + i] != s[r - i]) {
                flag = false;
                break;
            }
            i++;
        }
        return flag;
    }

    string longestPalindrome(string s) {

        int leader = 0, width = 0;
        int lagger = 0;

        // vector<int> ans (1001);
        int requiredLagger=s.length();
        int n = s.length();


         while (leader < n) {
           if(s[leader] == s[lagger] && leader != lagger)
           {
            cout << "leader " << leader << " lagger: " << lagger << endl;
               if(isPalin(s,lagger,leader))
               {
                   if(leader-lagger+1 > width){
                    requiredLagger = lagger;
                    width = leader - lagger + 1;
                   }
                   
               } else {
                lagger++;
               }
            
           }
           leader++;
        }


        return s.substr(requiredLagger, width);
    }

int main()
{
    string s = "cbbd";
    cout << longestPalindrome(s) << endl;
    // cout << endl;
    // s = "babad";
    // cout << longestPalindrome(s) << endl;
    // cout << endl;
    
    cout << endl;
    return 0;
}