#include<bits/stdc++.h>
using namespace std;

   DLLNode* reverseDLL(DLLNode* head) {

    if(!head && !head->next){
      return head;
    }

        DLLNode* t1 = head;
        DLLNode* t2 = head->next;
        DLLNode* t3 = NULL;
        
        while(t1)
        {
            t1->next = t3;
            t1->prev = t2;
            t3 = t1;
            t1 = t2;
            if(t2) t2 = t2->next;
        }
        
        return t3;
        
    }

int main(){



  cout << '\n';
  return 0;
}