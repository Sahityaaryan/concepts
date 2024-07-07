#include <bits/stdc++.h>
using namespace std;

ListNode *detectCycle(ListNode *head)
{

    if (!head || !head->next)
    {
        return head;
    }

    ListNode *hare = head;
    ListNode *tort = head;

    while (hare && hare->next)
    {
        hare = hare->next->next;
        tort = tort->next;

        if (hare == tort)
        {
            break;
        }
    }

    if (hare == tort)
    {

        tort = head;

        while (tort != hare)
        {
            hare = hare->next;
            tort = tort->next;
        }

        return tort;
    }

    return nullptr;
}

int main()
{

    cout << endl;
    return 0;
}