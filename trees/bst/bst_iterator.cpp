#include<iostream>
using namespace std;

/*
 *
 * 173. Binary Search Tree Iterator
 *
 *
 * Learning this is the new question I have seen in the bst I have solve this with 
 * 1. T.C : O(1) and s.c :O(N)
 * 2. T.C : O(N) and s.c : O(1)
 *
 * but this solution is really awesome.
 * */

class BSTIterator {
public:
    stack<TreeNode*> st;
    void build_stack(TreeNode* root){
        if(!root) return;
        st.push(root);
        build_stack(root->left);
    }

    BSTIterator(TreeNode* root) {
        build_stack(root);
    }
    
    int next() {
        if(st.empty()) return -1;

        TreeNode* node = st.top(); st.pop();
         build_stack(node->right);
        return node->val;
    }
    
    bool hasNext() {
        return !st.empty();
    }

    // T.C=> O(1) or O(logN)
    // S.C => O(logN)
};


int main(){

    return 0;
}
