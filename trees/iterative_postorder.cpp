


# include<bits/stdc++.h>
using namespace std;


struct Node {
    int data;
    Node* left;
    Node* right;
    Node() : data(0), left(nullptr), right(nullptr) {}
    Node(int x) : data(x), left(nullptr), right(nullptr) {}
    Node(int x, Node *left, Node *right) : data(x), left(left), right(right) {}
};



vector<int> postOrder(Node* node) {

     // vector<int> post;

     // stack<pair<Node*, bool>> st;
     // st.push({node, false});

     // while(!st.empty()){

     //     if(st.top().second){
     //         post.push_back(st.top().first->data);
     //         st.pop();
     //         continue;
     //     }

     //     st.top().second = true;

     //     Node* root = st.top().first;


     //     if(root->right){
     //         st.push({root->right, false});
     //     }

     //     if(root->left){
     //         st.push({root->left, false});
     //     }
     // }

     // return post;

         // T.C : O(N)
 // S.C :O(2log(N)-1)



 // -----------------------------> Optimized solution<----------------


 // Mantra :-> root left right + revers


     vector<int> post;

     stack<Node*> st;

     st.push(node);

     while(!st.empty()){

         node = st.top();
         st.pop();

         if(node->left) st.push(node->left);
         if(node->right) st.push(node->right);

         post.push_back(node->data);

     }

     reverse(post.begin(), post.end());

     return post;

     // T.C : O(N + N/2)
     // S.c: O(N)

 }



 int main(){

     return 0 ;
 }
