#include<bits/stdc++.h>
using namespace std;

Node* makeCopy(Node* head,unordered_map<Node*, Node*>& mp, Node* copyListHead ){
        
        if(!head){
            return NULL;
        }

        Node* newNode = new Node(head->val);
        mp[head] = newNode;

        newNode->next = makeCopy(head->next, mp, copyListHead);
        newNode->random = mp[head->random];

        copyListHead = newNode;

        return copyListHead;
    }

    Node* copyRandomList(Node* head) {

        unordered_map<Node*, Node*> mp;
        return makeCopy(head,mp,nullptr);
        
        // N = number of nodes
        // T.C : O(N)
        // S.C : O(N)
    }

int main()
{
    cout << endl;
    return 0;
}