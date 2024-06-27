#include<bits/stdc++.h>
using namespace std;

void deleteNode(ListNode* node) {
        ListNode* temp = node;

        while(temp->next->next){
            temp->val = temp->next->val;
            temp = temp->next;
        }

        temp->val = temp->next->val;

        // ! why even after deleting the second last pointer we are assignig a null pointer
        // * after deallocating the memory space pointing the temp->next, makes it a dangling pointer
        // * means it is still pointing to a deallocated memory space so we points it to nullptr

        delete temp->next;
        temp->next = nullptr; 
        
    }

int main()
{
 
    
    cout << endl;
    return 0;
}