#include<bits/stdc++.h>
using namespace std;
 

//  987(Hard) vertical Order Traversal of a Binary Tree -> https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree/description/


   map<int, vector<vector<int>>> mp;
    
    void vertical_width(tn* root, int breadth, int depth){
        if(!root) return;
        if(mp[breadth].size() <= depth){
            mp[breadth].resize(depth+1);
        }
        mp[breadth][depth].push_back(root->val);
        vertical_width(root->left, breadth-1, depth + 1);
        vertical_width(root->right, breadth+1, depth + 1);
    }

    vector<vector<int>> verticalTraversal(TreeNode* root) {
        
        vertical_width(root,0,0);
        vector<vector<int>> ans(mp.size());
        int i = 0;
        for(auto it:mp){

            vector<int> temp;

            for(auto x:it.second){
                sort(x.begin(), x.end());
                temp.insert(temp.end(), x.begin(), x.end());
            }
            
            ans[i] = temp;
            i++;
        }

        return ans;     
    }

int main(){
    
 cout << endl;
return 0;
}