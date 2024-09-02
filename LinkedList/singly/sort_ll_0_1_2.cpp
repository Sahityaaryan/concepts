#include<bits/stdc++.h>
using namespace std;

       Node* segregate(Node *head) {
         Node* zeroHead = NULL;
         Node* oneHead = NULL;
         Node* secondHead = NULL;
         Node* zero = new Node(0);
         zeroHead = zero;
         Node* one = new Node(1);
         oneHead = one;
         Node* two = new Node(2);
         secondHead = two;

        while(head){
                Node* temp = new Node(head->data);

            if(!head->data){
                zero->next = temp;
                zero = zero->next;
            } else if(head->data == 1){
                one->next = temp;
                one = one->next;
            } else {
                two->next = temp;
                two = two->next;
            }

            head = head->next;
        }


       if(zeroHead->next){

           if(oneHead->next){
               zero->next = oneHead->next;
           }

           if(secondHead->next){

               if(oneHead->next){
                   one->next = secondHead->next;
               } else {
               zero->next = secondHead->next;
               }
           }

               return zeroHead->next;
       }


           if(oneHead->next){

               if(secondHead->next){
                   one->next = secondHead->next;
               }

               return oneHead->next;
           }


           return secondHead->next;
    }

int main()
{


    cout << endl;
    return 0;
}
