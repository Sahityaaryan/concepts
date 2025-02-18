#include<iostream>
using namespace std;

/*
* 1. Build bst from inorder
* 2. Build bst from preorder
*
*
*/


typedef TreeNode tn;


// inorder approach

vector<int> bst;

 tn* build_bst( int l, int r){

    if(l > r) return nullptr;
    int mid = l + (r-l)/2;

    tn* new_node = new tn(bst[mid]);
    tn* new_node->left = build_bst(l, mid-1);
    tn* new_node->right = build_bst(mid+1, r);
    return new_node;
}


void inorder(tn* root){

    if(!root) return;
    
    inorder(root->left);
    bst.push_back(root->val);
    inorder(root->right);
}

// preorder approach


/**
1. Method (pick the new number to add and start traversing all the time from the root to the correct place)
T.c: O(N^2)

2. Method (sort the preorder which will give the inorder and now build one tree using them)
T.C: O(nlogn + n)

3. Method (The bounded approach) 
T.C: O(3*N)

*/

    TreeNode* bstFromPreorder(vector<int>& preorder) {
       int pre_index = 0;
        return build_bst_pre(pre_index, preorder, INT_MAX);
    }

    tn* build_bst_pre(int& pre_index, vector<int>& preorder, int ub){
        
        if(pre_index >= preorder.size()) return nullptr;
        int data = preorder[pre_index];

        if(data > ub) return nullptr;
        
        tn* new_node = new tn(data);
        pre_index++;
        new_node->left = build_bst_pre(pre_index, preorder, new_node->val);
        new_node->right = build_bst_pre(pre_index, preorder, ub);

        return new_node;
    }


int main(){

    return 0;
}
