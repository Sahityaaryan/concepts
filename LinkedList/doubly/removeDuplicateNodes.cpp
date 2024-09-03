#include<bits/stdc++.h>
using namespace std;

    Node * removeDuplicates(struct Node *head)
    {
        Node* temp = NULL;
        Node* nextNode = NULL;
        Node* currNode = head;

        while(currNode){
            nextNode = currNode->next;

            while(nextNode && currNode->data == nextNode->data){ // we aren't deleting the current node we are deleting the next node
                temp = nextNode;
                nextNode = nextNode->next;

                delete temp;
                temp = NULL;
            }

                currNode->next = nextNode;
            if(nextNode){
                nextNode->prev = currNode;
            }

            currNode = nextNode;
        }

        return head;

        // T.C : O(N)
        // S.C : O(1)

    }

int main()
{
    cout << endl;
    return 0;
}
