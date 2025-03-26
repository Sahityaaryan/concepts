#include<bits/stdc++.h>
using namespace std;

/*
 
link:-> https://leetcode.com/problems/kth-largest-element-in-an-array/description/

 This question is about finding the kth largest element using minheap.

 descrition: -> If you look closely you will notice that in the agenda of preserving only k elements in the min heap, you are actually removing (n-k) small 
 elements. 
*/

class Solution {
    public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> minheap;

        for(int ele:nums){
            minheap.push(ele);
            if(minheap.size() > k) minheap.pop();
        }
        return minheap.top();
    }
    };

int main(){
    
 cout << endl;
return 0;
}