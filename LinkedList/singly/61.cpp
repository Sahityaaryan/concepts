#include<bits/stdc++.h>
using namespace std;

/**
 * 
 * * Hurrah ! I have done this solution in more good time complexity than the sir's solution
 * 
 * * Time complexity: O(N)
 * * Space complexity: O(1)
 * 
*/
    void rotateList(ListNode*& start, int& k, ListNode* end, int& size){

        if(!end){
            return;
        }
        
        size++;
        
        rotateList(start,k,end->next, size);

        if(!end->next && k){
            k %= size;
            end->next = start;
        }

        if(k==0 && size){
            start = end->next;
            end->next = nullptr;
            size = 0;
        }

        if(k > 0){
            k--;
        }

    }

    ListNode* rotateRight(ListNode* head, int k) {

        if(!head ){
            return head;
        }

        if(!k || !head->next){
            return head;
        }

        int size = 0;

        rotateList(head,k,head,size);

        return head;
        
    }

    // T.C : O(N)
    // S.C : O(1)

    // Justification: Here I am doing using recursion to call for only upto (N) times (N = size of the list) and manipulating the links
    // of the list at the required node when it the recurstion is retracing itself, and as there is no any other operations 
    // Hence its time complexity is equal to the number of times the recursive function gets called which is O(N).

    // Posted Solution:

    // T.C : O(2N - k)
    // As it first finds the length through traversal and then traverse to the N-k th node 

    link(To Posted solution): https://takeuforward.org/data-structure/rotate-a-linked-list/ 


int main()
{
    
    cout << endl;
    return 0;
}