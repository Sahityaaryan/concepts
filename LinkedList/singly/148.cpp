#include<bits/stdc++.h>
using namespace std;

/**
 *  My solution
 * 
*/

//  void printList(ListNode* head){
//      ListNode* t = head;
//      cout << "\nList: ";
//      while(t){
//          cout << " " << t->val;
//          t = t->next;
//      }
//  }

//     ListNode* MidL(ListNode* head , ListNode* end){

//        ListNode* hare = head;
//        ListNode* tort = head;

//         while(hare != end && hare->next != end){  
//             hare = hare->next->next;
//             tort = tort->next;
//         }

//         return tort;
//     }

//     ListNode* LastNodeL(ListNode* head){
//         ListNode* hare = head;

//         while(hare->next){
//             hare = hare->next;
//         }

//         return hare;
//     }

//     void mergeL(ListNode* head, ListNode* mid,ListNode* end){

//         ListNode* t1 = new ListNode(head->val);
//         ListNode* firstHead = t1;
//         ListNode* t2 = new ListNode(mid->next->val);
//         ListNode* secondHead = t2;
//         ListNode* t = head;

//     //   formation of LinkedList

//     while(t->next != mid->next){
//         t = t->next;
//         ListNode* temp = new ListNode(t->val);
//         t1->next = temp;
//         t1 = t1->next;
//     }

//     t = mid->next;

//     while(t->next != end->next){
//         t = t->next;
//         ListNode* temp = new ListNode(t->val);
//         t2->next = temp;
//         t2 = t2->next;
//     }
//         // Merging

//        t1 = firstHead;
//        t2 = secondHead;
//         t = head;

//          while(t1 && t2 ){
            
//             if(t1->val < t2->val){
//                 t->val = t1->val;
//                 t1 = t1->next;
//             } else {
//                 t->val = t2->val;
//                 t2 = t2->next;
//             }

//             t = t->next;
//          }

//          while(t1){
//             t->val = t1->val;
//             t = t->next;
//             t1 = t1->next;
//          }  

//          while(t2){
//             t->val = t2->val;
//             t = t->next;
//             t2 = t2->next;
//          }

//         //  clean Up of used spaces

//         delete t1;
//         t1 = nullptr;

//         delete t2;
//         t2 = nullptr;
//     }

//     void mergeSortL(ListNode* head, ListNode* end){
        
//         if(!head || !end){
//             return;
//         }

//         if(head != end){

//             // Mid:
//         ListNode* mid = MidL(head,end);
//         mergeSortL(head,mid);
//         mergeSortL(mid->next, end);

//         mergeL(head,mid,end);
//         }
//         return;
//     }

//     ListNode* sortList(ListNode* head) {

//         if(!head || !head->next){
//             return head;
//         }

//         ListNode* end = LastNodeL(head);

//         mergeSortL(head , end);

//         return head;
//     }

//     // Time Complexity: N*( 1 + 3*(logN)/2)


/**
 *  Best Time complexity
 * 
*/

// ListNode* middle(ListNode* &head){
//         ListNode*slow= head;
//         ListNode*fast= head->next;
//         while(fast!=NULL &&fast->next!=NULL){
//             slow=slow->next;
//             fast= fast->next->next;
//         }   
//         return slow;
//     }

//     ListNode* merge(ListNode* &left, ListNode* &right){
//         if(left==NULL) return right;
//         if(right==NULL) return left;
//         ListNode* temp= new ListNode(-1);
//         ListNode* mptr= temp;

//         while(left!=NULL && right!=NULL){
//             if(left->val <= right->val){
//                 mptr->next=left;
//                 mptr=left;
//                 left=left->next;
//             }
//             else{
//                 mptr->next=right;
//                 mptr=right;
//                 right=right->next;
//             }
//         }
//         while(left!=NULL){
//             mptr->next=left;
//             mptr=left;
//             left=left->next;
//         }
//         while(right!=NULL){
//             mptr->next=right;
//             mptr=right;
//             right=right->next;
//         }
//         return temp->next;
//     }

//     ListNode* sortList(ListNode* head) {
//         if(head==NULL || head->next==NULL){
//             return head;
//         }

//         //break into two halves
//         ListNode* mid= middle(head);
//         ListNode* left= head;
//         ListNode* right= mid->next;
//         mid->next=NULL;
        
//         //Sort 
//         left=sortList(left);
//         right=sortList(right);

//         ListNode* mergeLL= merge(left,right);
//         return mergeLL;   

//     }

int main()
{
    cout << endl;
    return 0;
}