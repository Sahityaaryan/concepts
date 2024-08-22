#include<bits/stdc++.h>
using namespace std;

 ListNode* deleteMiddle(ListNode* head) {

        if(!head || !head->next){
            return nullptr; 
        }

        ListNode* hare = head;
        ListNode* tort = head;
        ListNode* followerTort = nullptr;

        while(hare && hare->next){
            followerTort = tort;
            tort = tort->next;
            hare = hare->next->next;
        } 

        followerTort->next = tort->next;
        
        delete tort;
        tort = nullptr;

        return head;        
    }

int main()
{
    
    cout << endl;
    return 0;
}