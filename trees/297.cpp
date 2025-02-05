#include<bits/stdc++.h>
using namespace std;
 


/*

    297: Serialize and Deserialize Binary Tree   () https://leetcode.com/problems/serialize-and-deserialize-binary-tree/ ()

    How my code is working: 
    for input : [1,2,3, null, null, 4,5];

    string formed =>  "1 | 2 3 | n n 4 5 | n n n n |"

    now at the desiralize
    I am just putting it using intuition

    Problem: Why i didn't use the 2*i + 1 approach?

        because i have to make an array for that so it will take an extra space and time complexity
        of O(N)


*/

class Codec {
public:

// firt attempt:-> 1hrs and 26 minutes 

    // Encodes a tree to a single string.
    string serialize(TreeNode* node) {

        if(!node) return "";

       stringstream serial;

       queue<TreeNode*> q;

       q.push(node);

       while(!q.empty()){

        int n = q.size();

        while(n--){
            TreeNode* root = q.front();q.pop();
            if(!root){
                serial << " n";
                continue;
            }
            string num = " ";
            num.append(to_string(root->val));

            serial << num;

            q.push(root->left);
            q.push(root->right);
        }
        serial << " |";

       }

        return serial.str();
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string str) {

        if(str.empty()) return nullptr;
    
        stringstream data(str);

    
        queue<TreeNode*> q;
        string temp;
        data >> temp;
        TreeNode* root = new TreeNode(stoi(temp));

        TreeNode* node = root;

        q.push(root);

        while(data >> temp){
            if(temp == "|") continue;
            
            int qsize = q.size();

            while(qsize--){
                root = q.front();q.pop();

                if(!root) continue;
                TreeNode* left = nullptr;
                TreeNode* right = nullptr;

                if(temp != "n")left = new TreeNode(stoi(temp));
                data >> temp;
                if(temp != "n")right = new TreeNode(stoi(temp));
                data >> temp;
                root->left = left;
                root->right = right;

                q.push(left);
                q.push(right);
            }
        }
        return node;
    }


int main(){
    
 cout << endl;
return 0;
}