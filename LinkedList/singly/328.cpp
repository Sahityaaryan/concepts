#include <bits/stdc++.h>
using namespace std;

ListNode* oddEvenList(ListNode* head) {

    if(!head || !head->next){
        return head;
    }

    ListNode* odd = head;
    ListNode* even = head->next;
    ListNode* oddHead = odd;
    ListNode* evenHead = even;

    while(even){

        if(even->next){ // for even sized list
            odd -> next = even -> next;
            odd = odd->next;
        } else {
            break;
        }

        even->next = odd->next;
        even = even->next;
    }

    odd->next = evenHead;
1
    return oddHead;
}
int main()
{

    cout << endl;
    return 0;
}
