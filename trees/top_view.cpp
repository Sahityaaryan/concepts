#include<bits/stdc++.h>
using namespace std;
 

     vector<int> topView(Node *root) {
        // code here
        
        map<int, Node*> roots;
        queue<pair<Node*, int>> q;
        
        q.push({root, 0});
        
        while(!q.empty()){
            pair<Node*, int> p = q.front();
            q.pop();
            root = p.first;
            
            if(!roots[p.second]){
                roots[p.second] = root;
            }
            
            if(root->left) q.push({root->left, p.second-1});
            if(root->right) q.push({root->right, p.second+1});
        }
        
        vector<int> top_view;
        
        for(auto x:roots){
            top_view.push_back(x.second->data);
        }
        
        return top_view;
    }


int main(){
    
 cout << endl;
return 0;
}