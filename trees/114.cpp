#include<bits/stdc++.h>
using namespace std;
 
 /*
 114. Flatten Binary Tree to Linked List
 
 https://leetcode.com/problems/flatten-binary-tree-to-linked-list/description/


 */

    void flat(TreeNode* root, TreeNode*& tipNode){
        if(!root)return;

        tipNode = root;
        TreeNode* node = root->left;
        root->left = root->right;
        root->right = node;

        if(root->right){
            flat(root->right, tipNode);
        } 

        if(root->left){
            tipNode->right = root->left;
            root->left = nullptr;
            flat(tipNode->right,tipNode);
        }

    }

    void flatten(TreeNode* root) {
        if(!root) return;
        TreeNode* tipNode = root;
        flat(root,tipNode);
    }

    // s.c : O(1)
    // T.C : O(N)

int main(){
    
 cout << endl;
return 0;
}