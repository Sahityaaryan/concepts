#include<bits/stdc++.h>
using namespace std;


// concept m == (2*x) - ((2*x) - m)

// Here I got the most of the logic but i couldn't get as where to store the complex (result of substrction) 
// but the solution is to store that "complex" in the stack itself and you will identify the complex as the complex will always be less than the min_ele
class MinStack {

    #define ll long long

        stack<ll>minstack;
        int min_ele = INT_MAX;
        

public:
    MinStack() {}
    
    void push(int val) {

        if(minstack.empty()){
            min_ele = val;
            minstack.push(val);
        } else {

            if(val < min_ele){
                ll complex = (2*val - min_ele);
                min_ele = val;
                minstack.push(complex);
                return;
            }
            minstack.push(val);
        }
        
    }
    
    void pop() {
        
        if(minstack.top() < min_ele){
            ll complex = minstack.top();
            min_ele = 2*min_ele - complex;
        }

        minstack.pop();
    }
    
    int top() {
        return minstack.top();
    }
    
    int getMin() {
        return min_ele;
    }
};



int main()
{
 
    
    cout << endl;
    return 0;
}