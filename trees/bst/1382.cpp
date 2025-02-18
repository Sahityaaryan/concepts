#include<bits/stdc++.h>
using namespace std;

/**
 *  1. build bst from inorder 
 *  2. build bst from preorder
*/

typedef TreeNode tn;
class Solution {
public:
    vector<int> nodes;
    
    void inorder(tn* root){
        
        if(!root) return;
        
        inorder(root->left);
        nodes.push_back(root->val);
        inorder(root->right);
    }

    tn* build_bst(int l, int r){
        if(l > r) return nullptr;

        int mid = l + (r-l)/2;
        tn* node = new tn(nodes[mid]);
        
        node->left = build_bst(l, mid-1);
        node->right = build_bst(mid+1, r);

        return node;
    }
    TreeNode* balanceBST(TreeNode* root) {
        inorder(root);
        
        return build_bst(0, nodes.size()-1);
        
    }
};



/*
 * This is one of the most interesting question 
 *
 * 1. Method (building tree while traversing again and again from the root node to find the right place for the current value in the preorder) T.C:(N^2)
 *
 * 2. Method (sorting the entire preorder to get the inorder now you have preorder and inorder of a tree then build a unique tree using it ) T.C :O(nlogn + n)
 *
 * 3. Method (using the upperbound which helps us to determine whether the current position is right for insertion or not) T.C : O( 3*n) 
 *
 *
 *
 * */




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
};



int main(){

    return 0;
}
