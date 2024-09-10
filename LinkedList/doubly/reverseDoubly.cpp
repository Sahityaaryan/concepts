#include<bits/stdc++.h>
using namespace std;

Node* reverseDLL(Node * head)
{
    // In place replacement
        
        Node* t1 = head;
        Node* t2 = new Node(0);
        Node* t3 = new Node(0);
        
        while(t1){
            t3 = t1;
            t2 = t1->next;
            t1->next = t1->prev;
            t1->prev = t2;
            t1 = t2;
        }
        
        return t3;
    
}

int main()
{
    cout << endl;
    return 0;
}