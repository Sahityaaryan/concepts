#include<bits/stdc++.h>
using namespace std;
 

/*

    Morris Traversal

    
    Learning : when you are using morris traversal just you have to see the traversal pattern and then decide 
    which nodes you have to connect and with whom and then simply apply it.

    This is based on two conditions

    1. if(root->left == nullptr) then 
        print(root)

        we will check futher how can we move the root either from right or thread if none 
        of them exists break the loop

    2. else 

        if(thread exists at the right_most root) then
            you have already traversed the left so
             -> remove the thread
             -> move futher eithher to right or if the thread exist on the root else break

        else 
            -> create one thread
            -> and move to the left s
*/


struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


    tn* rightMost(tn* root){
        while(root->right){
            root = root->right;
        }
        return root;
    }

    vector<int> inorderTraversal(TreeNode* root) {
        if(!root) return {};

        vector<int> inorder;
        unordered_map<tn*, tn*> thread;

        while(true){
            if(root->left){
                tn* right_most = rightMost(root->left);
                if(thread[right_most]){ // you have already traversed to the left part
                    thread[right_most] = nullptr;
                    inorder.push_back(root->val);

                    // this is the case when you have to move the pointer to something because 
                    // now you can't go left as you have already traversed so only two ways 
                    // remaining for you either go to right or to your thread if none exists
                    // it means you have traversed the tree
                    if(root->right)root = root->right; 
                    else if(thread[root]) root = thread[root];
                    else break;
                } else {

                    // case when you haven't traversed to the left part
                    thread[right_most] = root;
                    root = root->left;
                }
            } else { // you don't have a left part for traversal
                inorder.push_back(root->val);

                // this case have also similar choices as the above but the situation is 
                // different in the above case you have traversed the left so you can't go to 
                // left but here you have no left at all.

                if(root->right) root = root->right;
                else if(thread[root]) root = thread[root];
                else break;
            }
        }


        return inorder;
    }




/*
        Morris Traversal (Preorder)

    
*/
    TreeNode* rightMost(TreeNode* root){
        if(!root) return nullptr;

        while(root->right || root->left){
            if(root->right)root = root->right;
            else if(root->left)root = root->left;
        }
        return root;
    }

    vector<int> preorderTraversal(TreeNode* root) {
        if(!root) return {};
        vector<int>pre;
        unordered_map<TreeNode*, TreeNode*> thread;

        while(true){
            if(root->right){
                if(root->left){
                TreeNode* node = rightMost(root->left);
                thread[node] = root->right;
                }
            }
            pre.push_back(root->val);

            if(root->left) root = root->left;
            else if(root->right) root = root->right;
            else if(thread[root]) root = thread[root];
            else break;
        }
        return pre;
    }

int main(){
    
 cout << endl;
return 0;
}