#include<bits/stdc++.h>
using namespace std;


// 2415. Reverse Odd Levels of Binary Tree (https://leetcode.com/problems/reverse-odd-levels-of-binary-tree/)


 struct TreeNode {
     int val;
     TreeNode* left;
     TreeNode* right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };


 // MY way along with bfs
     void bfs(TreeNode* &root, vector<TreeNode*>& vec, int i){
     if(i >= vec.size()) return;
     root = vec[i];
     bfs(root->left, vec, 2*i+1);
     bfs(root->right, vec, 2*i+2);
 }

 TreeNode* reverseOddLevels1(TreeNode* root) {

     if(!root) return root;

     deque<TreeNode*> q;
     q.push_back(root);q.push_back(nullptr);

     bool odd_level = true;

     while(!q.empty()){

         if(q.front() == nullptr){

             if(q.size() == 1) break; // this is a necessay condition as when there is only nullptr
             // in the deque

             if(odd_level){

                 for(int i = 1; i < (q.size()+1)/2; i++){
                     swap(q[i]->val, q[q.size()-i]->val);
                 }
             }

             odd_level = !odd_level;
             q.push_back(nullptr);

         } else {
             if(q.front()->left) q.push_back(q.front()->left);
             if(q.front()->right) q.push_back(q.front()->right);
         }
         q.pop_front();
     }

     return root;
 }

 // T.C : O(2N)
 // S.C : O(2N + log(N+1))


 // --------------------------------------------------Optimized way-----------------------------------------
TreeNode* reverseOddLevels(TreeNode* root) {

    // The nullptr is after all the nodes of a particular level as an indication that all the nodes of a particular level are finished

        deque<TreeNode*> q;
        q.push_back(root);
        q.push_back(nullptr);
        bool oddLevel = true;
        while(true) {
            if(q.front() == nullptr) {
                if(q.size() == 1) break;

                if(oddLevel) {
                    for(int i = 1; i < (q.size() + 1) / 2; i++) { // it is just changing the interchaninging the values of the nodes ith and n-1-ith node
                        swap(q[i]->val, q[q.size() - i]->val);
                    }
                }
                oddLevel = !oddLevel;

                q.push_back(nullptr);
            } else {
                if(q.front()->left != nullptr) q.push_back(q.front()->left);
                if(q.front()->right != nullptr) q.push_back(q.front()->right);
            }
            q.pop_front();
        }
        return root;
    }

    // T.C : O(N + (4^((log(N+1))/2) - 1)/3)
    // S.C : O(N)


    int main(){


        cout << "Jai Mata Di\n";


        deque<int> d;

        d.push_front(1);
        d.push_front(2);
        d.push_front(3);
        d.push_front(4);

        for(int i = 0; i < d.size(); i++){
            cout << d[i] << ' ';
        }

        return 0;
    }
