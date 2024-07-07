#include<bits/stdc++.h>
using namespace std;

ListNode* middleNode(ListNode* head) {
    ListNode* slow = head;
    ListNode* fast = head;
    while (fast != nullptr) {
    if (fast->next != nullptr){
        if (fast->next->next != nullptr){
            fast = fast->next->next;
            slow = slow->next;
        }
        else if (fast->next->next == nullptr){
            fast = fast->next;
            slow = slow->next;
        }
    }
    else if (fast->next == nullptr)
        break;
}
return slow;

}

int main()
{
 
    
    cout << endl;
    return 0;
}