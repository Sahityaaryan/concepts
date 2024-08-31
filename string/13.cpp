#include<bits/stdc++.h>
using namespace std;

    int guessTheValue(char str){

        if(str == 'I'){
            return 1;
        } else if(str == 'V'){
            return 5;
        } else if(str == 'X'){
            return 10;
        } else if(str == 'L'){
            return 50;
        } else if(str == 'C'){
            return 100;
        } else if (str == 'D'){
            return 500;
        } else {
            return 1000;
        }
    }

    // **** More optimized solution 

    int romanToInt(string s) {

        int ans = 0;
        int n = s.length();
        int i = n-2;
        int top = guessTheValue(s[n-1]); 

          bool topIsFilled = true;

        while(i>=0){


            while( i>=0 && top > guessTheValue(s[i])){
                top -= guessTheValue(s[i]);
                i--;
            }

            ans += top;
            topIsFilled = false;

          if(i>=0){
            top = guessTheValue(s[i]);
            topIsFilled = true;
            } 

            i--;
        }

        
        return topIsFilled ? ans+top:ans;

        // T.C:  O{N}
        // S.C : O(1)
    }

    //**  By  Stack

    int romanToInt1(string s) {

        stack<char> st;

        int i = 0, value1, value2, ans=0;

        while(i < s.length()){
            st.push(s[i++]);
        }

        i = 0;

        value1 = guessTheValue(st.top());
        st.pop();
         ans += value1;

        while(!st.empty()){
          
          value2 = guessTheValue(st.top());

          st.pop();

          if(value2 < value1){
            ans -= value2;
          } else {
            ans += value2;
          }
          value1 = value2;
        }

        return ans;

        
    }


/***
 * *By recursion
 * 
*/

    int sol(string s,int& topElementValue, int ind){

        if(ind == s.length()){
            return 0;
        }
        
       int value = sol(s,topElementValue, ind+1);

        int currentDigit = guessTheValue(s[ind]);

        if(topElementValue > currentDigit){
            return value - currentDigit;
        }

        topElementValue = currentDigit;

        return value + currentDigit;
    }

    int romanToInt2(string s) {
        int topElementValue = 0;
      return sol(s,topElementValue,0);  

    // T.C : O(N)
    // S.C : O(N)
    }

int main()
{
    
    cout << endl;
    return 0;
}