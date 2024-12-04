#include<bits/stdc++.h>
using namespace std;
 

// } Driver Code Ends
class Solution
{
    public:
    
    // Trick :- median is that number in the array from which half of the number is greater and other half will be smaller
    
    priority_queue<int> s;
    priority_queue<int, vector<int>, greater<int>> g;
    
    //Function to insert heap.
    void insertHeap(int &x)
    {
        
         if(s.size() == 0) {
            s.push(x);
            return;
        }

        if(s.size() > g.size()){
            if(x < s.top()){
                g.push(s.top());
                s.pop();
                s.push(x);
            } else {
                g.push(x);
            }
        } else {
            if(x < s.top()){
                s.push(x);
            } else {
                g.push(x);
                s.push(g.top());
                g.pop();
            }
        }
    }
    
    //Function to balance heaps.
    void balanceHeaps()
    {}
    
    //Function to return Median.
    double getMedian()
    {   
        if(s.size() == g.size()){
            return (double)(s.top() + g.top()) / 2.0;
        } 
        
        return s.top(); 
        
    }
};


//{ Driver Code Starts.

int main()
{
    int n, x;
    int t;
    cin>>t;
    while(t--)
    {
    	Solution ob;
    	cin >> n;
    	for(int i = 1;i<= n; ++i)
    	{
    		cin >> x;
    		ob.insertHeap(x);
    	    cout << floor(ob.getMedian()) << endl;
    	}
    
cout << "~" << "\n";
}
	return 0;
}
// } Driver Code Ends

class MedianFinder {
public:
        priority_queue<int> s;
        priority_queue<int, vector<int>, greater<int>> g;
    MedianFinder() {

        
    }
    
    void addNum(int num) {
        
        if(s.size() == 0){
            s.push(num);
            return;
        }

        if(s.size() != g.size()){

            if(num < s.top()){ // abhi num top se chota and size unequal hai toh mujhe size equal karni hai mujhe s.top() ko maxlist mein dalna hoga and then use add karenge
                g.push(s.top());
                s.pop();
                s.push(num);
            } else { // aur if num greater hai then toh use maxlist main hi daal do
                g.push(num);
            }
        } else {

            if(num < s.top()){ // dekho agar num chota hai min list ke max se toh direct usme daal do
                s.push(num);
            } else { // agar wo bada hai toh chances ho sakte hai usse koi chota maxlist me present ho toh isliye use maxList mein dal do aur wo minheap hai toh minimum top pe aa jayega and use small list mein dal do
                g.push(num);
                s.push(g.top());
                g.pop();
            }
        }
    }
    
    double findMedian() {
        
        if((s.size() + g.size()) & 1){
            return s.top();
        }

        return (double) (s.top() + g.top()) / 2.0;
    }
};