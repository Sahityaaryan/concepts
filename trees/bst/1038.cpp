#include<bits/stdc++.h>
using namespace std;

/**
 * 
 * Learning : Descending order from the bst
 */

typedef TreeNode tn;
class Solution {
public:

    void sol(tn* root, int& prev){
        if(!root) return;

        sol(root->right, prev);
        root->val += prev;
        prev = root->val;
        sol(root->left, prev);
    }
    TreeNode* bstToGst(TreeNode* root) {
        int prev = 0;
        sol(root,prev);

        return root;
    }
};


int main(){

    return 0;
}
