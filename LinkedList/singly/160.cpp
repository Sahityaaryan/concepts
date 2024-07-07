#include<bits/stdc++.h>
using namespace std;

/***
 * 
 * My solution with the best time complexity ever solved
 * 
 * but must checkout other solutions: https://takeuforward.org/data-structure/find-intersection-of-two-linked-lists/
*/

// ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {

//         int s1 = 1;
//         int s2 = 1;

//         ListNode* hareA = headA;
//         ListNode* hareB = headB;

//         vector<ListNode*> backTraceA, backTraceB;

//         while((hareA && hareA->next) && (hareB && hareB->next)){
//             backTraceB.emplace_back(hareB);
//             backTraceB.emplace_back(hareB->next);
//             backTraceA.emplace_back(hareA);
//             backTraceA.emplace_back(hareA->next);
//             hareA = hareA->next->next;
//             hareB = hareB->next->next;
//         }

//         while(hareA && hareA->next) {
//             backTraceA.emplace_back(hareA);
//             backTraceA.emplace_back(hareA->next);
//             hareA = hareA->next->next;
//         }

       
//         if(hareA && !hareA->next){
//             backTraceA.emplace_back(hareA);
//         }

//         while(hareB && hareB->next) {
//             backTraceB.emplace_back(hareB);
//             backTraceB.emplace_back(hareB->next);
//             hareB = hareB->next->next;
//         }


//         if(hareB && !hareB->next){
//             backTraceB.emplace_back(hareB);
//         }

//         int i = backTraceA.size()-1, j = backTraceB.size()-1;

//         if(backTraceA[i] != backTraceB[j]){
//             return nullptr;
//         }
        
//         while(i > 0 && j>0 && backTraceA[i] == backTraceB[j]){
//             i--;
//             j--;
//         }

//         ListNode* temp1 = backTraceA[i];
//         ListNode* temp2 = backTraceB[j];

//         while(temp2 && temp1 && temp1 != temp2){
//             temp1 = temp1->next;
//             temp2 = temp2->next;
//         }

//         if(temp1){
//             return temp1;
//         }

//         return nullptr;

//         // k = number of similar nodes
//         // N = size of bigger linkedList
        
//         // Time Complexity: O(N/2 + k)
//         // Space Complexity: O(N)
//     }

int main()
{
    
    cout << endl;
    return 0;
}