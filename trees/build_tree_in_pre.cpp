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


// sir's approach -> less optimized
//
// T.C : O(NlogN)
// S.C : O(logN)
//

TreeNode* buildNode(vector<int>& preorder, vector<int>& inorder,int InStart,int InEnd, int& preIndex) {
       if(InStart>InEnd) return NULL;

       //building the node first and then it will be connected on it's own
       TreeNode* newNode = new TreeNode (preorder[preIndex]);


       //searching for the node element in the inorder to get its right and left
       // nodes as well from inorder

       int i = InStart;

       while(i <= InEnd)
       {
           if(inorder[i]==preorder[preIndex]) break;
           i++;
       }

         preIndex++;//updating the value of preIndex

       //searching for the other nodes as well

       newNode->left = buildNode(preorder,inorder,InStart,i-1,preIndex);
       newNode->right = buildNode(preorder,inorder,i+1,InEnd,preIndex);

       //now as we got clear that who are the descendants of the newNode then we
       //can return the newNode to its parent
       return newNode;

}

TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
   int InStart = 0,InEnd = inorder.size()-1;
   int preIndex = 0;

 return  buildNode(preorder,inorder,InStart,InEnd,preIndex);

}


// Mine Solution --> Optimized solution
//
// T.C : O(N)
// S.C : O(N + logN)
//


// loved the question --> it is all about domain sorting technique and how the
// inorder and preorder gives the range of the things

// Inorder -> is best for the range selection like which range of index cotains nodes of my left subtree and which does the same for my right subtree

// preorder -> is used to find the next root

// For achienving even less time complexity I am using map

    int root_ind = -1;

    TreeNode* build_tree(unordered_map<int, int>& in_mp, int in_l, int in_r, vector<int>& pre){

        if(in_l > in_r) return nullptr;

        TreeNode* new_node = new TreeNode(pre[++root_ind]);

        int root_in_inorder = in_mp[pre[root_ind]];

        new_node->left = build_tree(in_mp, in_l, root_in_inorder-1, pre);
        new_node->right = build_tree(in_mp, root_in_inorder+1, in_r, pre);

        return new_node;
    }

    TreeNode* buildTree1(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int, int> in_mp;
        for(int i = 0;i < inorder.size(); i++){
            in_mp[inorder[i]] = i;
        }
        return build_tree(in_mp, 0, inorder.size()-1, preorder);
    }

int main(){

    return 0;
}
