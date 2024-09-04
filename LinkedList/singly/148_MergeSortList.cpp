#include<bits/stdc++.h>
using namespace std;


// I have chosen to form a LinkedList here because there is a time complexity of O(N) and S.C : O(2*logN)

ListNode* middle(ListNode* &head){
        ListNode*slow= head;
        ListNode*fast= head->next;
        while(fast!=NULL &&fast->next!=NULL){
            slow=slow->next;
            fast= fast->next->next;
        }
        return slow;
    }

    ListNode* merge(ListNode* &left, ListNode* &right){
        if(left==NULL) return right;
        if(right==NULL) return left;
        ListNode* temp= new ListNode(-1);
        ListNode* mptr= temp;

        while(left!=NULL && right!=NULL){
            if(left->val <= right->val){
                mptr->next=left;
                mptr=left;
                left=left->next;
            }
            else{
                mptr->next=right;
                mptr=right;
                right=right->next;
            }
        }

        while(left!=NULL){
            mptr->next=left;
            mptr=left;
            left=left->next;
        }
        while(right!=NULL){
            mptr->next=right;
            mptr=right;
            right=right->next;
        }
        mptr = mptr->next;

        delete right;
        delete left;
        delete mptr;

        return temp->next;
    }

    ListNode* sortList(ListNode* head) {
        if(head==NULL || head->next==NULL){
            return head;
        }

        //break into two halves
        ListNode* mid= middle(head);
        ListNode* left= head;
        ListNode* right= mid->next;
        mid->next=NULL;

        //Sort
        left=sortList(left);
        right=sortList(right);

        ListNode* mergeLL= merge(left,right);
        return mergeLL;
    }

int main()
{
    cout << endl;
    return 0;
}
