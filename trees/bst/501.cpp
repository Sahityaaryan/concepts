#include<bits/stdc++.h>
using namespace std;


/*
    501. Find Mode in Binary Search Tree

    Learning: I have almost close to the actual approach but i was stuck into using a map I wasn't able
    to think approaches other than the maps,, #ripLogicBuilding
*/
    void mode_analyzer(tn* root,int& prev, int& max_freq, int& curr_freq, vector<int>& result){
        if(!root) return;

        mode_analyzer(root->left, prev, max_freq, curr_freq, result);
        
        if(prev == root->val) curr_freq++;
        else curr_freq = 1;

        if(curr_freq > max_freq){
            max_freq = curr_freq;
            result.clear();
            result.push_back(root->val);
        } else if(curr_freq == max_freq){
            result.push_back(root->val);
        }
        
        prev = root->val;
        mode_analyzer(root->right, prev, max_freq, curr_freq, result);
    }

    vector<int> findMode(TreeNode* root) {
        // unordered_map<int, int> mp;
        int prev = -1, max_freq = 0, curr_freq = 0;
        vector<int> mode_nodes;
        mode_analyzer(root, prev, max_freq, curr_freq, mode_nodes);
        return mode_nodes;
    }


int main(){


    return 0;
}
