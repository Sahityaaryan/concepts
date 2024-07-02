#include<bits/stdc++.h>
using namespace std;

// Recursive version

    ListNode* reverseLl(ListNode* head,ListNode*& secondHead){

        if(!head->next){
            secondHead = head;
            return head;
        }

        ListNode* prev = reverseLl(head->next, secondHead);

        prev->next = head;

        return head;
    }
     
    ListNode* reverseList(ListNode* head) { 

        if (!head || !head->next){
            return head;
        }
    
        ListNode* secondHead = nullptr;
        ListNode* t = reverseLl(head,secondHead);

        t->next = nullptr;

        return secondHead;
    }

int main()
{

    
    cout << endl;
    return 0;
}