#include <bits/stdc++.h>
using namespace std;

ListNode *oddEvenList(ListNode *head)
{

    if (!head || !head->next)
    {
        return head;
    }

    ListNode *odd = head;
    ListNode *even = head->next;
    ListNode *evenHead = head->next;
    ListNode *tempOdd = nullptr;
    ListNode *tempEven = nullptr;

    while (even && even->next)
    {
        tempOdd = odd->next->next;
        tempEven = even->next->next;

        odd->next = tempOdd;
        even->next = tempEven;

        odd = tempOdd;
        even = tempEven;
    }

    odd->next = evenHead;

    return head;
}

int main()
{

    cout << endl;
    return 0;
}