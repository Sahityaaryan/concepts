#include<bits/stdc++.h>
using namespace std;

    Node * removeDuplicates(struct Node *head)
    {
        Node* temp = NULL;
        Node* nextNode = NULL;
        Node* currNode = head;
        
        while(currNode){
            nextNode = currNode->next;
            
            while(nextNode && currNode->data == nextNode->data){
                 temp = nextNode; 
                nextNode = nextNode->next;
                
                delete temp;
                temp = NULL;
                
            }
            
            if(!nextNode){
                
                currNode->next = nextNode;
                
            } else {
                currNode->next = nextNode;
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