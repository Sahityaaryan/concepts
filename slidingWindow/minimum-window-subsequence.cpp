#include<bits/stdc++.h>
using namespace std;

// question:-> https://www.geeksforgeeks.org/problems/minimum-window-subsequence/1

    string minWindow(string& s1, string& s2) {
       string minWindString = "";
       int window = 0, lead1 = 0, lead2 = 0, lag = 0, min_window = INT_MAX;
       
       while(lead1 < s1.length() && lead2 < s2.length()){
           
           if(s1[lead1] == s2[lead2]){
               lead2++;
           }
           
           if(lead2 == s2.length()){
               lag = lead1;
               lead2--;
               
               while(lag >=0 && lead2 >= 0){
                   if(s1[lag] == s2[lead2]){
                       lead2--;
                   }
                   lag--;
               }
               lag++;
               lead2 = 0;
               
               window = lead1-lag+1;
               
               if(min_window > window){
                   min_window = window;
                   minWindString = s1.substr(lag, window);
               }
               
               lead1 = lag+1;
           }
           
           lead1++;
       }
       
       return minWindString;
    }

    // T.C : O(s1.length()*s2.length())
    // S.C : O(1)


int main(){

    // string str1 = "geeksforgeeks", str2 = "eksrg";
        string str1 = "aiafceccfgdgikfkgkeaheijjccigaahdabhfikadkejfbjjhkecdkkkcjcjddfhac", str2 = "afgkjcjca";
    string ns = minWindow(str1, str2);    

    cout << "ans: " << ns;
 cout << endl;
return 0;
}

// afceccfgdgikfkgkeaheijjccigaahdabhfikadkejfbjjhkecdkkkcjcjddfha
