#include<bits/stdc++.h>
using namespace std;

/*
    222. Count Complete Tree Nodes

*/ 

  int leftHeight(TreeNode* root){
        if(!root) return 0;
        int lh = 0;
        while(root){
            lh++;
            root = root->left;
        }

        return lh;
    }

    int rightHeight(TreeNode* root){
        if(!root) return 0;
        int rh = 0;
        while(root){
            rh++;
            root = root->right;
        }

        return rh;
    }

    int countNodes(TreeNode* root) {
        if(!root) return 0;

        int lh = leftHeight(root);
        int rh = rightHeight(root);

        if(lh == rh) return (1 << lh) -1;

        return 1 + countNodes(root->left) + countNodes(root->right);    
    }

int main(){
    
 cout << endl;
return 0;
}