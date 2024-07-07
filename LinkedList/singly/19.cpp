#include<bits/stdc++.h>
using namespace std;

// *** hare tortoise 

        ListNode* removeNthFromEnd(ListNode* head, int n) {

            ListNode* tort = head;
            ListNode* hare = head;

            while(n--){
                hare = hare->next;
            }

            // head removal case

            if(!hare){
                hare = tort->next;  
                delete tort;
                tort = nullptr;
                return hare;
            }

            while(hare->next){
                hare = hare->next;
                tort = tort->next;
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