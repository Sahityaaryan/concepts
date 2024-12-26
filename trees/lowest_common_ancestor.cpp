#include <bits/stdc++.h>
using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
};

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {

       if(!root) return root;

       if(root == p || root == q ){
           return root;
       }

       TreeNode* search_ancestor_at_left =  lowestCommonAncestor(root->left, p, q);
       TreeNode* search_ancestor_at_right =  lowestCommonAncestor(root->right, p, q);

       // this is based on an assumption that the both nodes are present in the tree
       // and if you get a node from either left or right and a null from other out of them
       // then which side you get a node also contains the other node and these if statements signifies
       // the same thing

       if(!search_ancestor_at_left) return search_ancestor_at_right;
       if(!search_ancestor_at_right) return search_ancestor_at_left;

       return root; // if none of them are null it means both of the nodes are found either side of the
       // root hence the root is the required ancestor
   }

   int main(){

       return 0;
   }
