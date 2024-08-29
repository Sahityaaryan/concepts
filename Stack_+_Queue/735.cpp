#include <bits/stdc++.h>
using namespace std;

vector<int> asteroidCollision(vector<int>& asteroids) {

    stack<int> st;

    for(int ele:asteroids){

        if(ele > 0){
            st.push(ele);
        } else {

            while(!st.empty() && (st.top() > 0) && st.top() < abs(ele)){
                st.pop();
            }

            if(!st.empty() && st.top() == abs(ele)){ // here we have introduced this thing because if the asteroids are of equal size then we won't store it in stack
                st.pop();
            } else if(st.empty() || st.top() < 0){
                st.push(ele);
            }
        }
    }

    int n = st.size();
    vector<int> arr(n);

    for(int i = n-1; i >= 0; i--){
        arr[i] = st.top();
        st.pop();
    }

    return arr;
}

// S.C : O(2N)
// T.C : O(2N)

int main(){

    return 0;
}
