#include<bits/stdc++.h>
using namespace std;

Node* reverseDLL(Node * head)
{
    // In place replacement
    
    if(!head){
        return head;
    }
    
    Node* t1 = head;
    Node* t2 = t1;
    
    while(t1){
        t2 = t1;
        t1->next = t1->prev;
        t1->prev = t2;
        t1 = t1->prev;
    }
    
    return t3;
    
}

int main()
{
    cout << endl;
    return 0;
}