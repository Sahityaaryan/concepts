#include<bits/stdc++.h>
using namespace std;

void deleteNode(ListNode* node) {
        ListNode* temp = node;

        while(temp->next->next){
            temp->val = temp->next->val;
            temp = temp->next;
        }

        temp->val = temp->next->val;

        delete temp->next;
        temp->next = nullptr; 
        
    }

int main()
{
 
    
    cout << endl;
    return 0;
}
        
