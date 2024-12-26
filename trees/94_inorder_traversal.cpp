#include <bits/stdc++.h>
using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
};

class Solution {
public:
    vector<int> ele;
    vector<int> inorderTraversal(TreeNode* root) {
        if(!root) return ele;

        inorderTraversal(root->left);
        ele.push_back(root->val);
        inorderTraversal(root->right);
        return ele;
    }
};

int main(){

    return 0;
}
