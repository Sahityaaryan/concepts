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

int countNodesinLoop(Node *head) {

        int count = 0;

    if (!head || !head->next)
    {
        return 0;
    }

    Node *hare = head;
    Node *tort = head;

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
            count++;
            hare = hare->next;
            tort = tort->next;
        }

        return count-1;
    }

    return 0;

    }
