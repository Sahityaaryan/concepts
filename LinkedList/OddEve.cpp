#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//# leet code: 328

ListNode *oddEvenList(ListNode *head)
{

    if (head == NULL || head->next == NULL || head->next->next == NULL)
    {
        return head;
    }
    ListNode *odd = head;
    ListNode *oddHead = head;
    ListNode *even = head->next;
    ListNode *evenHead = head->next;

    while (even)
    {
        odd = odd->next = even->next;

        if (odd)
        {
            even = even->next = odd->next;
        }
        else
            break;
    }

    ListNode *t = oddHead;

    while (t->next != NULL)
    {
        t = t->next;
    }

    t->next = evenHead;

    return oddHead;
}

