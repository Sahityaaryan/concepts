#include<bits/stdc++.h>
using namespace std;
 
 struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x):val(x), left(nullptr), right(nullptr){}
 };

     vector<vector<int>> levelOrder(TreeNode* root) {

        if(!root){
            return {};
        }
        
        queue<TreeNode*> q;
        vector<vector<int>> ans;

        q.push({root});

        int level = -1; // this is a variable just to show you that how to calculate the level of the tree
        while(!q.empty()){
            int n = q.size(); // here it showing the number of nodes in the level
            level++;
            vector<int> temp;

            while(n--){ 
                root = q.front();
                temp.push_back(root->val);
                if(root->left) q.push(root->left);
                if(root->right) q.push(root->right);
                q.pop();
            }

            ans.push_back(temp);
            temp.clear();
        }
        
        return ans;  

    }


int main(){
    
 cout << endl;
return 0;
}