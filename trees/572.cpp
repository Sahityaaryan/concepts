
#include<bits/stdc++.h>
using namespace std;

 struct TreeNode {
     int val;
     TreeNode* left;
     TreeNode* right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };

bool is_same_tree(TreeNode* root, TreeNode* sub_root){
    if(!root && !sub_root) return true;
    if(!root || !sub_root) return false;
    if(root->val != sub_root->val) return false;

    bool left_check = is_same_tree(root->left, sub_root->left);
    bool right_check = is_same_tree(root->right, sub_root->right);

    return left_check && right_check;

}

void is_root_present(TreeNode* root, TreeNode* sub_root, vector<TreeNode*>& v) {

    if(!root || !sub_root) return;
    if(root->val == sub_root->val) v.push_back(root);

    is_root_present(root->left, sub_root, v);
    is_root_present(root->right, sub_root, v);

}

bool isSubtree(TreeNode* root, TreeNode* sub_root) {

    if(root == sub_root) return true;
    if(!root || !sub_root) return false;

    vector<TreeNode*> similar_nodes;

    is_root_present(root, sub_root, similar_nodes);

    //  = false;

    for(int i = 0; i < similar_nodes.size(); i++){
    bool root_has_subroot = is_same_tree(similar_nodes[i], sub_root);
    if(root_has_subroot) return true;
    }

    return false;

}

int main(){

    return 0;
}
