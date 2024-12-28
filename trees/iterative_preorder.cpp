

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



// Mantra => root, right, left (order of pushing elements in the stack)


vector<int> preorderTraversal(TreeNode* root) {

    if(!root) return {};

    stack<TreeNode*> st;
    vector<int> pre;

    st.push(root);

    while(!st.empty()){

        root = st.top();
        st.pop();
        pre.push_back(root->val);

        if(root->right) st.push(root->right);
        if(root->left) st.push(root->left);
    }

    return pre;
}


int main(){

    vector<int> v ={1,2,3};

    cout << v.back() << '\n';

    return 0 ;
}

// T.C : O(N)
// S.C : O(3) == O(1)
