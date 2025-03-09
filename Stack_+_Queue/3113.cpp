#include <iostream>

long long numberOfSubarrays(vector<int>& nums) {
        stack<int> st;
        long long count = 0;
        int pop_ele = -1;
        int adder = 1;
        for(int ele:nums){
                adder = 1;
                pop_ele = -1;
            while(!st.empty() && st.top() < ele){
                if(pop_ele == st.top()) adder++;
                else adder = 1;
                count+= adder;
                pop_ele = st.top();
                st.pop();
            }
            st.push(ele);
        }

        pop_ele = -1;
        adder = 1;

        while(!st.empty()){
            if(pop_ele == st.top()) adder++;
                else adder = 1;

                count+= adder;
                pop_ele = st.top();
                st.pop();
        }

        return count;
    }

int main(){

    return 0;
}
