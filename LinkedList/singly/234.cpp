#include<bits/stdc++.h>
using namespace std;

    // **  optimal approach

    ListNode* reverseList(ListNode* head){

        if(!head || !head->next){
            return head;
        }

        ListNode* t1 = head;
        ListNode* t2 = head->next;
        ListNode* t3 = NULL;

        while(t1){

            t1->next = t3;
            t3 = t1;
            t1 = t2;
            if(t2) t2 = t2->next;
        }

        return t3;
    }

    bool isPalindrome(ListNode* head) {

        if (!head || !head->next) {
            return true;
        }

        int i = 0, n;

        stack<int> st;

        ListNode* hare = head;
        ListNode* tort = head;

        while(hare && hare->next){ // I got the middle node
            hare = hare->next->next;
            tort = tort->next;
        }

        ListNode* newHead = reverseList(tort); // reversed the middle half


        hare = head;


        while(hare != tort){ // Now checking the reversed half with the first half
            if(hare->val != newHead->val){
                return false;
            }
            hare = hare->next;
            newHead = newHead->next;
        }

        return true;

        // T.C : O(N/2 + N/2 + N/2)
        // S.C : O(1)
    }


    // Recursive approach

bool recursiveChecking(ListNode* last, ListNode*& head ){
        if(!last){
            return true;
        }

        bool isPalin = recursiveChecking(last->next, head) && (last->val == head->val);
        head = head->next;

        return isPalin;

    }

    bool isPalindrome(ListNode* head) {
        return recursiveChecking(head,head);

        // Best T.C : then the iterative solution O(N)

        // T.C : O(N)
        // S.C : O(N)
    }


int main(){



    return 0;
}
