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

    int romanToInt(string s) {

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

int main()
{
 
    
    cout << endl;
    return 0;
}