#include<bits/stdc++.h>
using namespace std;

    ListNode* deleteMiddle(ListNode* head) {

        if(!head || !head->next){
            return nullptr;
        }

        ListNode* hare = head->next;
        ListNode* tort = head;

        while(hare->next && hare->next->next){
            tort = tort->next;
            hare = hare->next->next;
        } 

        hare = tort->next->next;
        delete tort->next;
        tort->next = nullptr;

        tort->next = hare;

        return head;        
    }

int main()
{
    
    cout << endl;
    return 0;
}