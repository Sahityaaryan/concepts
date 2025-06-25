#include<bits/stdc++.h>
using namespace std;
 

// 662.  maximum width of the binary tree



struct TreeNode{
    int val;
    struct TreeNode* left;
    struct TreeNode* right;

    TreeNode(): val(0), left(nullptr), right(nullptr){}
};

typedef TreeNode tn;


/*
 Problems
 1. Should be using indexed approach
 2. Have to make initialise each level of the nodes with index 0 so that it won't result in overflow
 3. I should be using "unsigned int" because it can store a much greater value then the range of the "int" 
 */


    int widthOfBinaryTree(TreeNode* root) {

        if(!root) return 0;

         int width = INT_MIN;

        queue<pair<tn*,unsigned int>> q;

        q.push({root, 0});

        while(!q.empty()){

            int n = q.size();
            int firstInd = q.front().second;
            unsigned int lastInd = q.front().second;


            while(n--){
                unsigned int i = q.front().second-firstInd; // it is literally generating the index from 0 to whatever it can go
                root = q.front().first;
                lastInd = i;
                q.pop();


                if(root->left) q.push({root->left, 2*i + 1});
                if(root->right) q.push({root->right, 2*i + 2});

            }

            width = max(width, (int)lastInd+1);

        }

        return width;
        
    }

int main(){
    
 cout << endl;
return 0;
}