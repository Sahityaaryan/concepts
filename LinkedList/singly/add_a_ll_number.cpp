#include<bits/stdc++.h>
using namespace std;

/**
 * *I have solved it by three ways : 
 * 
 * *second is more optimized on space basis: O(1)
 * 
 * *third is ultra optimized
 * 
*/


// Node* addOne(Node *head) 
//     {
//         // In place changes: Need of the hare and Tortoise
        
//         if(!head){
//             return NULL;
//         }
        
//         bool flag = head->data == 9;
        
//         Node* temp = head;
        
//         vector<Node*> v;
        
//         while(temp->next){
            
//             if( temp->next->data == 9) {
//                 v.emplace_back(temp);
//             }
            
//             temp = temp->next;
//         }
        
//         if(temp->data == 9) {
            
//             temp->data = 0;
            
//             int i = v.size()-1;
            
//             while((i+1 > 0) && (v[i]->data == 9)){
//                 v[i]->data = 0;
//                 i--;
//             }
            
            
           
//             if(i+1 && v[i]->data < 9){
//                 // add the one till the head node if it is less than 9
//                 v[i]->data += 1;
                
//             } else{
                
//                 Node* newHead = new Node(1);
//                 newHead->next = head;
//                 return newHead;
//             } 
            
//         } else {
//             temp->data += 1;
//         }
        
//         return head;
        
        
//         // T.C : O(2N)
//         // S.C: O(N)
        
//     }


//    Node* rotateList(Node* head){
        
//         Node* a = head;
//         Node* b = head->next;
//         Node* c = NULL;
        
//         while(a){
//             a->next = c;
//             c = a;
//             a = b;
//         if(b) b = b->next;
//         }
        
//         return c;
//     }
    
//     Node* addOne(Node *head){
//         // In place changes: Need of the hare and Tortoise
        
//         if(!head){
//             return NULL;
//         }
        
//         bool originalHeadHasBeenChanged = false;
        
//         Node* rotatedHead =  rotateList(head);
        
//         Node* temp = rotatedHead;
        
//         while(temp && temp->data == 9){
                
//                 temp->data = 0;
//                 if(!temp->next){
//                    originalHeadHasBeenChanged = true; 
//                 }
//                 temp = temp->next;
//             }
            
//             if(originalHeadHasBeenChanged){
//                 Node* newHead = new Node(1);
//                 head->next = newHead;
//                 return rotateList(rotatedHead);
//             } else {
//                 temp->data += 1;
//             }
            
//             return rotateList(rotatedHead);
            
//             // T.C = O(3N)
//             // S.C = O(1)
//     }

    void recursiveAddition(Node* head, int& carry){
        
        if(!head){
            return;
        }
        
        recursiveAddition(head->next, carry);
        
        if(carry){
            
            if(head->data < 9){
                
                head->data += 1;
                carry = 0;
                
            } else {
                head->data = 0;
            }
        }
    }
    
    Node* addOne(Node *head){
       
       int carry = 1;
       
       recursiveAddition(head,carry);
       
       if(!head->data){
           
           Node* newHead = new Node(1);
           newHead->next = head;
           return newHead;
       }
       
       return head;
       
    //   T.C = O(N)
    //   S.C = O(1)
    }

int main()
{
 
    
    cout << endl;
    return 0;
}