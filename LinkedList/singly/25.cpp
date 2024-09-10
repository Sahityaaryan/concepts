#include<bits/stdc++.h>
using namespace std;

/**
 * * I am really proud of me I have solved the question in more optimized way as compare to sir's solution
 * * check the second solution
*/

    // ListNode* reverseLL(ListNode* head, ListNode* end){

    //     if(!head || !head->next){
    //         return head;
    //     }

    //     ListNode* a = head;
    //     ListNode* b = head->next;
    //     ListNode* limit = (end->next) ? end->next: nullptr;
    //     ListNode* c = limit;

    //     while(a != limit){
    //         a->next = c;
    //         c = a;
    //         a = b;
    //         if(b) b = b->next;
    //     }

    //     return c;
    // }

    // ListNode* reverseKGroup(ListNode* head, int k) {
    //     vector<ListNode*> v;
    //     ListNode* t = head;

    //     int p = k;

    //     while(t){
    //       p = k-1;
    //         while(t && p){            list2 = list2->bottom;
        }
        res->next = NULL;
    }

    if(list1){  
        res->bottom = list1;
    } else {
        res->bottom = list2;
    }
    //         t = t->next;
    //         p--;
    //       }

    //       if(!p && t){
    //         v.emplace_back(t);
    //       }
    //      if(t) t = t->next;
    //     }

    //     p = 1;

    //     ListNode* nextHead = v[0]->next;
    //     ListNode* prevHead = head;
    //     ListNode* ansHead = reverseLL(head,v[0]);


    //     while(p < v.size()){ 
    //        nextHead = prevHead->next;
    //        prevHead->next = reverseLL(prevHead->next,v[p]); 
    //        prevHead = nextHead;  
    //       p++;
    //     }
    //     t = v[0];

    //     return ansHead;

    //     // T.C : O(2N)
    //     // S.C : O(N/k)
    // }

    /**
     * 
     * * Second and the most optimized solution 
    */


    ListNode* reverseLL(ListNode* head, ListNode* end){

        if(!head || !head->next){
            return head;
        }

        ListNode* a = head;
        ListNode* b = head->next;
        ListNode* limit = (end->next) ? end->next: nullptr;
        ListNode* c = limit;

        while(a != limit){
            a->next = c;
            c = a;
            a = b;
            if(b) b = b->next;
        }

        return c;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {

        ListNode* t = head;
        ListNode* nextHead = head;
        ListNode* prevHead = head;
        ListNode* ansHead = nullptr;
        ListNode* newHead = nullptr;
        ListNode* currHead = head;

        int p = k;

        while(t){

          p = k-1;
            while(t && p){
            t = t->next;
            p--;
          }


          if(!p && t){
            nextHead = t->next;
            newHead = reverseLL(currHead,t);

            if(!ansHead){
                ansHead = newHead;
            } else {
                prevHead->next = newHead;
            }

            prevHead = currHead;
            currHead = nextHead; 
            t = nextHead;

          } else {
           if(t) t = t->next;
          }
        }

        return ansHead;

        // T.C : O(2N - N/k)  = ((N/k)*k + N- (N/k) )
        // S.C : O(1)

        // Justification: 

        // Due to single loop I am iterating to every nodes but there is a difference of T.C at N/k nodes rest N-N/k nodes are passed as it is
        // In those N/k nodes I am reversing then and it takes additional T.C of k (k = size of the sublist) and hence those N/k nodes are 
        // making T.C of (N/k)*k which is equal to (N) so total Time complexity : O ( (N) + (N - N/k)) = O (2N - N/k)

        // Posted solution:
        // T.C : O( (N/k) * (2K) ) => O(2N)

        // I think they both are same. Because my loop is actually running N/k times only
    }

int main()
{
    
    cout << endl;
    return 0;
}