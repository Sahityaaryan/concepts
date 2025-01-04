
# include<bits/stdc++.h>
using namespace std;


struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// Post_order -> it will be used to give the root but the trick is we will start point the root_ind from the last because the postorder gives it's root from the last and we have to prefer the right of the node inorder to fill the tree

// rest is same the inorder will be used for the range purposes

    int root_ind;

    TreeNode* build_tree(unordered_map<int, int>& in_mp ,int in_l, int in_r, vector<int>& post){

        if(in_l > in_r) return nullptr;

        TreeNode* new_node = new TreeNode(post[--root_ind]);

        int ind_in_inorder = in_mp[post[root_ind]];

        new_node->right = build_tree(in_mp, ind_in_inorder+1, in_r, post);
        new_node->left = build_tree(in_mp, in_l, ind_in_inorder-1, post);

        return new_node;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if(!inorder.size()) return nullptr;
        root_ind = postorder.size();
        unordered_map<int, int> in_mp;

        for(int i = 0; i < inorder.size(); i++){
            in_mp[inorder[i]] = i;
        }

        return build_tree(in_mp, 0, inorder.size()-1, postorder);
    }


    int main(){

        return 0;
    }
