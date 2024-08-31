#include<bits/stdc++.h>
using namespace std;


int MOD = 1e9+7;

vector<int> nextSmallerElement(vector<int>& arr){

int n = arr.size();

stack<int> st;

vector<int> nse(n,n);

for(int i = n-1; i>=0; i--){

    while(!st.empty() && arr[st.top()] > arr[i]){ // Just notice that we aren't removing the index of the same value elements
    st.pop();
    }

    if(!st.empty()){
    nse[i] = st.top();
    }

    st.push(i);
}

return nse;

}

vector<int> prevSmallerElement(vector<int>& arr){

int n = arr.size();

stack<int> st;

vector<int> pse(n,-1);

for(int i = 0; i < n; i++){

    while(!st.empty() && arr[st.top()] >= arr[i]){
    st.pop();
    }

    if(!st.empty()){
    pse[i] = st.top();
    }

    st.push(i);
}

return pse;
}

int sumSubarrayMins(vector<int>& arr) {

    vector<int> pse = prevSmallerElement(arr);
    vector<int> nse = nextSmallerElement(arr);
    int n = arr.size(), sum = 0;

    for(int i = 0; i < n;i++){
        long long one = (i-pse[i]) * (nse[i] - i);
        long long mult = arr[i] * one;
        sum = ((long long)sum + mult ) % MOD;
    }

    return sum;
}


int main(){

    return 0;
}
