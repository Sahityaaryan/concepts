



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

//   I have used post order traversal to insert the leaf nodes path

  void find_leaf_nodes(Node* root, vector<int>& temp, vector<vector<int>>& leaf_nodes){

      if(!root) return;

      temp.push_back(root->data);

      find_leaf_nodes(root->left, temp, leaf_nodes);
      find_leaf_nodes(root->right, temp, leaf_nodes);

      if(!root->left && !root->right) leaf_nodes.push_back(temp);

      temp.pop_back();
  }

    vector<vector<int>> Paths(Node* root) {

        vector<vector<int>> leaf_nodes;
        vector<int> temp;

        find_leaf_nodes(root, temp, leaf_nodes);
        return leaf_nodes;
    }


    int main(){

        return 0;
    }
