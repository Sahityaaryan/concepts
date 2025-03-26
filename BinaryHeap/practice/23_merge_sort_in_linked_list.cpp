#include<bits/stdc++.h>
using namespace std;


 /*

 link: -> leetcode.com/problems/merge-k-sorted-lists/

 description:-> (I have seen someone else's) he applied the concept of merge sort in linked list to solve this
 and thus providing me a way to implement things in linked list for merge sort

 */
 

 class Solution {
    public:
        ListNode* mergeKLists(vector<ListNode*>& lists) {
          
            if(lists.empty()) return nullptr;
    
            return partition(lists, 0, lists.size()-1);
        }
        
    private:
    
        ListNode* partition(vector<ListNode*>& lists, int start, int end){
            
            if(start == end) return lists[start];
            if(start > end) return nullptr;
    
            int mid = start + (end-start)/2;
            ListNode* left = partition(lists, start, mid);
            ListNode* right = partition(lists, mid+1, end);
    
            return merge(left, right);
        }
    
        ListNode* merge(ListNode* left, ListNode* right){
    
            if(!left) return right;
            if(!right) return left;
    
            if(left->val < right->val){
                left->next = merge(left->next, right);
                return left;
            } 
            
            right->next = merge(left, right->next);
            return right;  
        }
        
    };
    


int main(){
    
 cout << endl;
return 0;
}