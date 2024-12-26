
node* bfs(int i, vector<int>& vec){
    if(i >= vec.size()) return NULL;

    node* root = newNode(vec[i]);
    root->left = bfs(2*i + 1, vec);
    root->right = bfs(2*i + 2, vec);

    return root;

}
void create_tree(node* &root0, vector<int> &vec){
    //Your code goes here
    root0 = bfs(0,vec);
}
