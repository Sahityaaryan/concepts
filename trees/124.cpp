#include<bits/stdc++.h>
using namespace std;
 


//  124(Hard) -> Max Path Sum

// Leaerning: you just have to do traversal but it is also a ground to up traversal question, the learning is not a new just some other way of thinking at the queston

//   Definition for a binary tree node.

  struct TreeNode {
      int val;
      TreeNode*left;
      TreeNode*right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode*left, TreeNode*right) : val(x), left(left), right(right) {}
  };

 typedef TreeNode tn;
class Solution {
public:

    int max_path_sum = INT_MIN;
    
    int path_sum(TreeNode* root){
        if(!root) return 0;

        int left_path_sum = max(path_sum(root->left), 0);
        int right_path_sum = max(path_sum(root->right), 0);
        
        int root_path_sum = right_path_sum + left_path_sum + root->val;

        max_path_sum = max(max_path_sum,root_path_sum);
        
        return root->val + max(left_path_sum , right_path_sum);
    }

    int maxPathSum(TreeNode* root) {
        int root_path_sum = path_sum(root);
        return max_path_sum;
    }
};

int main(){
    
 cout << endl;
return 0;
}