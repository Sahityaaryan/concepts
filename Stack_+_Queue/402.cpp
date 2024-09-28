#include<bits/stdc++.h>
using namespace std;


string removeKdigits(string num, int k) {

    int n = num.length();

    if(n == k){
        return "0";
    }

    stack<char> st;
    int i = 0;

    while(i < n){

        while(!st.empty() && (int)st.top() > (int)num[i] && k > 0){
            st.pop();
            k--;
        }

        st.push(num[i]);
        i++;
    }

    while(k > 0 && !st.empty()){
      st.pop();
      k--;
    }

   string ans = "";

    while(!st.empty()){
        ans += st.top();
        st.pop();
    }

    reverse(ans.begin(), ans.end());
        

     i = 0;

    while(ans[i] == '0' && i < ans.length()-1){
        i++;
    }

    return ans.substr(i, ans.length()-i);
}

int main(){

    string s = "1432219";
    s = "10";
    s = "112";

    cout << "\nans: " << removeKdigits(s, 1);

    return 0;
}
