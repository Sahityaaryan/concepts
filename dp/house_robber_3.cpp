#include<bits/stdc++.h>
using namespace std;

typedef TreeNode tn;


/*
    T.C : O(N)
    S.C : O(1)

*/
pair<int, int> dfs(tn* root){
     if(!root) return {0, 0};

     pair<int, int> l = dfs(root->left);
     pair<int, int> r = dfs(root->right);

     int take = root->val + l.second + r.second;
     int not_take = max(l.first, l.second) + max(r.first, r.second);

     return {take, not_take};
 }

 int rob(TreeNode* root) {

     if(!root) return 0;
     pair<int, int> p = dfs(root);

     return max(p.first, p.second);
 }

int main(){


    return 0;
}
