#include<bits/stdc++.h>
using namespace std;

    string trimString(string s){

        int start = 0, i = 0, n = s.length();

        while(i < n && s[i++]==' '){
            start++;
        }

        s = s.substr(start,s.length());

        int end = s.length()-1;

        i = s.length()-1;
        while(end>=0 && s[end]==' '){
            end--;
        }

        s = s.substr(0,end+1);
        return s;
    }

    int myAtoi(string s) {
        if(!s.length()){
            return 0;
        }
        string trimmedString = trimString(s);


        bool isNegative = false, doesAnyNonZeroAppeared = false, doesAnyDigitAppeared = false, doesSignAppeared = false;
        int n = trimmedString.length(), i = 0, ans = 0;

        if(!n){
            return n;
        }


        while(i < n){

            // checking for the non-digit integer

            if(trimmedString[i]-'0' > 9 || trimmedString[i]-'0' < 0){

                // check for the signs

               if(!doesSignAppeared){
                 if(trimmedString[i] == '-' && !doesAnyDigitAppeared){ 
                    isNegative = true;
                    doesSignAppeared = true;
                } else if(!(trimmedString[i]-'+')){
                    doesSignAppeared = true;
                } else {
                    return ans;
                }
               } else {
                    return (isNegative) ? -1*ans: ans;
               }
            }
        

            // leading zeros case

            if(trimmedString[i]-'0' <= 9 && trimmedString[i]-'0' >= 0){
                
                if(!doesAnyDigitAppeared) doesAnyDigitAppeared = true;

                if(!doesAnyNonZeroAppeared && trimmedString[i]-'0' > 0){
                doesAnyNonZeroAppeared = true;
                }
            

            if(doesAnyNonZeroAppeared){
              if(((long int)ans * 10) > INT_MAX){
                   return (isNegative) ? INT_MIN:INT_MAX;
              } else {
                ans *= 10;
              }

                if((trimmedString[i]-'0')){
                    if(((long int)ans + (trimmedString[i]-'0')) > INT_MAX){
                   return (isNegative) ? INT_MIN:INT_MAX;
              } else {
                    ans = ans + (trimmedString[i]-'0');
              }

                }
            }
            }

            i++;

        }

        return (isNegative) ? (-1*ans):ans;
    }

int main()
{
    string s = "-91283472332";

     s = "21474836++";

     cout << "ans: " << myAtoi(s);



    // cout << INT_MIN  <<' '  << pow(2,31);
    cout << endl;
    return 0;
}