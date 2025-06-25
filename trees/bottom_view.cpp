#include<bits/stdc++.h>
using namespace std;

/*

    Bottom View of Binary Tree

 */


    vector <int> bottomView(Node *root) {
        // Your Code Here
        queue<pair<Node*, int>> q;
        
        q.push({root, 0});
        map<int, int> roots;
        
        while(!q.empty()){
            
            pair<Node* , int> p = q.front();
            q.pop();
            root = p.first;
            
            roots[p.second] = root->data; 
            
            if(root->left) q.push({root->left, p.second-1});
            if(root->right) q.push({root->right, p.second+1});
        }
        
        
    
        vector<int> bottom_view;
        
        
        for(auto x:roots){
            bottom_view.push_back(x.second);
        }
        
        
        
        return bottom_view;
        
    }

 
int main(){
    
 cout << endl;
return 0;
}