#include<bits/stdc++.h>
using namespace std;


int largestRectangleArea(vector<int>& heights) {


    // Note: - here to solve this problem in the single go we can compute the pse but not the nse at the same time so we have used a simple observation that while calculating the pse if we are having to remove a particular element from the stack then it clearly shows that the current element is less than the stack elements and hence it is the nse for those stack elements

    // formula = height*(nse - pse - 1)

    int n = heights.size();
    int maxA = 0;
   vector<int> pse(n,-1);

   stack<int> st;

   for(int i = 0; i <= n; i++){

    while(!st.empty() && (i == n || (heights[st.top()] >= heights[i]))){ // here we aren't computing for the case if we don't find the next smaller till the end of the array so we have calculated the area on whatever top we have got so far

    // and if you observe closely the case (i == n) then you will realise it is calculating the area for each height in the stack

        int h = heights[st.top()];  
        int pse_ind = pse[st.top()];

        st.pop();

        maxA = max(maxA, h*(i - pse_ind -1));
    }

    if(!st.empty()){
        pse[i] = st.top();
    }

    st.push(i);
   }

   return maxA;

//    T.C : O(2N) // case: when the heights are sorted in the ascending order
// S.C : O(N)
}


int main(){
    return 0;
}
