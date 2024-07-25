#include<bits/stdc++.h>
using namespace std;

 vector<pair<int, int>> findPairsWithGivenSum(Node *head, int target){
        
        Node* leader = head;
        Node* lagger = head;
        
        vector<pair<int, int>> ans;
        
        int a,b;
        
        // N/2
        
        while(leader->next){
            
            if(!leader->next->next){
                leader = leader->next;
                
            } else {
                leader = leader->next->next;
            }
        }
        
        // N/2
        
        while(leader != lagger){
            
            a = leader->data;
            b = lagger->data;
            
            if(a+b == target){
                ans.emplace_back(pair<int, int>(b,a));
                lagger = lagger->next;
                
            } else if(a+b < target){
                lagger = lagger->next;
                
            } else {
                leader = leader->prev;
                
            }
        }
        
        return ans;
        
        // T.C : O(N)
        // S.C : O(N) -> because I have to submit the answer in this form
        
    }

int main()
{
    cout << endl;
    return 0;
}