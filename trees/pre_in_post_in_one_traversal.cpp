#include <bits/stdc++.h>
using namespace std;

#define tn TreeNode*


struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


void sol(TreeNode* root){

    if(!root) return;

vector<int> pre;
vector<int> in;
vector<int> post;

stack<pair<tn, int>> st;

st.push({root, 1});

while(!st.empty()){

    int num = st.top().second;
    root = st.top().first;

    if(num == 1){
        pre.push_back(root->val);
        st.top().second++;
        if(root->left) st.push({root->left,1});
    } else if(num == 2){
        in.push_back(root->val);
        st.top().second++;
        if(root->right) st.push({root->right,1});
    } else {
        post.push_back(root->val);
        st.pop();
    }
}

for(int ele:pre){
    cout << ' ' << ele;
}

cout << '\n';

for(int ele:in){
    cout << ' ' << ele;
}

cout << '\n';

for(int ele:post){
    cout << ' ' << ele;
}

}


int main(){

    return 0;
}
