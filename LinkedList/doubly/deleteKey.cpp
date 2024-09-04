#include <bits/stdc++.h>
using namespace std;

void deleteAllOccurOfX(struct Node **head_ref, int x)
{

    Node *t = (*head_ref);
    Node *head = (*head_ref);

    while (t)
    {

        if (t->data == x)
        {

            if (t == head)
            {
                head = head->next;
            }

            Node *nextNode = t->next;
            Node *prevNode = t->prev;

            if (nextNode)
                nextNode->prev = prevNode;
            if (prevNode)
                prevNode->next = nextNode;

            delete t;
            t = NULL;

            t = nextNode;
        }
        else
        {
            t = t->next;
        }
    }

    *head_ref = head;

    // T.C : O(N)
    // S.C : O(1)
}
int main()
{
    cout << endl;
    return 0;
}
