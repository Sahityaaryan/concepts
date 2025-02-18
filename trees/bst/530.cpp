#include<bits/stdc++.h>
using namespace std;
 
 /*
    530. Minimum Absolute Difference in BST

    Learning: Here this question taught me how can i gain access to the previous value or node in the bst.
*/
    int min_value = INT_MAX;

    void inorder(TreeNode* root, int& prev){
        if(!root) return;

        inorder(root->left, prev);
        min_value = min(abs(root->val-prev), min_value);
        prev = root->val;
        inorder(root->right, prev);
    }

    int getMinimumDifference(TreeNode* root) {
        int prev = INT_MAX;
        inorder(root,prev);
        return min_value;
    }

int main(){
    
 cout << endl;
return 0;
}