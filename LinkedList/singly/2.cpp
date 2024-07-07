#include<bits/stdc++.h>
using namespace std;

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // No need of recursion the digits are already reversed along with the carry game 
        
        ListNode* t = new ListNode(0);
        ListNode* ans = t;
        int sum = 0;

        int carry = 0;

        while(l1 || l2 || carry){
             
             sum = carry;

           if(l1){
             sum += (l1->val); 
           }

           if(l2){
            sum += (l2->val);
           }

           t->val = (sum % 10);

           if(sum/10){
            carry = 1;
           } else {
            carry = 0;
           }

           if(l1) l1 = l1->next;
           if(l2) l2 = l2->next;

           if(l1 || l2 || carry){
               ListNode* newNode = new ListNode();
               t->next = newNode;
               t = newNode;
           }
        }

        return ans;

        // N = bigger linkedList
        // T.C : O(N)
        // S.C : O(N)
    }

int main()
{
    
    cout << endl;
    return 0;
}