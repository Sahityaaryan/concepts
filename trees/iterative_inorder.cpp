
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



vector<int> inorderTraversal(TreeNode* root) {

    if(!root) return {};

    // you should memorise this code because this is producing the iterative
    // version of the inorder traversal and also preventing the problem of
    // restacking the left node
    vector<int> in;

    stack<TreeNode*> st;


    while(root || !st.empty()){

        while(root){
            st.push(root);
            root = root->left;
        }

        root = st.top();
        st.pop();
        in.push_back(root->val);

        root = root->right;
    }

    return in;
}

int main(){

    return 0 ;
}
