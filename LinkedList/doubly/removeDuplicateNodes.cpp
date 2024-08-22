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

    Node * removeDuplicates(struct Node *head)
    {
        Node* temp = head;
        Node* t;
        
        while(temp){
            
            while(temp->next && temp->next->data == temp->data){
                
                t = temp->next;
                
                temp->next = temp->next->next;
                temp->next->prev = temp;
                t->next = t->prev = NULL;
                
                delete t;
                t = NULL;
            } 
            temp = temp->next;
        }
        
        return head;
        
        // T.C : O(N)
        // S.C : O(1)
        
    }

