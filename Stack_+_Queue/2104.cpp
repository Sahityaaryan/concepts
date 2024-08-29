
#include<bits/stdc++.h>
using namespace std;

long long minimum_sum(vector<int>& arr){

    int n = arr.size();

    long long min_sum = 0;

        stack<int> st;

        // next smaller elements :  but note here we stop at the similar value element's index

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

        while(!st.empty()){
            st.pop();
        }

        // previous smaller elements : here we are ignoring the similar value element

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

        for(int i = 0; i < n ; i++){
            min_sum += (arr[i] * (i-pse[i]) * (nse[i] - i));
        }

        return min_sum;

}

long long maximum_sum(vector<int>& arr){

    int n = arr.size();

    long long max_sum = 0;

        stack<int> st;

        // next greater elements : but note here we stop at the similar value element's index

        vector<int> nge(n,n);

        for(int i = n-1; i>=0; i--){

            while(!st.empty() && arr[st.top()] < arr[i]){ // Just notice that we aren't removing the index of the same value elements
            st.pop();
            }

            if(!st.empty()){
            nge[i] = st.top();
            }

            st.push(i);
        }

        while(!st.empty()){
            st.pop();
        }

        // previous smaller elements : here we are ignoring the similar value element

        vector<int> pge(n,-1);

           for(int i = 0; i < n; i++){

               while(!st.empty() && arr[st.top()] <= arr[i]){
               st.pop();
               }

               if(!st.empty()){
               pge[i] = st.top();
               }

               st.push(i);
           }

        for(int i = 0; i < n ; i++){
            max_sum += (arr[i] * (i-pge[i]) * (nge[i] - i));
        }

        return max_sum
}


int main(){

    return 0;
}
