
#include<bits/stdc++.h>
using namespace std;
struct Node{
    int data;
    Node* left;
    Node* right;
};


// why the -1?
// because one right node reduce the left_width by one similary for the -1 at right_width

int left_width(Node* root, bool is_left){
    if(!root) return 0;

    int left_node_width = left_width(root->left, true);
    int right_node_width = left_width(root->right, false);

    return max(left_node_width, right_node_width) + (is_left  ? 1:-1);
}

int right_width(Node* root, bool is_right){
    if(!root) return 0;

    int left_node_width = right_width(root->left, false);
    int right_node_width = right_width(root->right, true);

    return max(left_node_width, right_node_width) + (is_right ? 1:-1);
}

int verticalWidth(Node* root) {

    if(!root) return 0;


    int left_width_from_left = left_width(root->left, true);
    int left_width_from_right = left_width(root->right, false);
    int right_width_from_left = right_width(root->left, false);
    int right_width_from_right = right_width(root->right, true);

    // Now this conditions are truly an edge case :-> (choosing the max
    // width no matter whether it is from right or left side)

    // because it is possible that the left side nodes can grow large enough internally more than the right
    // side nodes to the right side and vice versa.

    return 1 + max(left_width_from_right, left_width_from_left) + max(right_width_from_left, right_width_from_right);
}

// T.C : O(4*N) // as I am checking the widths for times in my code
// S.C : O(1)


// sir's approach


// unordered_set<int> st;

// void calchd(Node* root , int hd)
// {
//     if(root==NULL) return;

//     calchd(root->left,hd-1);
//     st.insert(hd);
//     calchd(root->right,hd+1);
// }


// //Function to find the vertical width of a Binary Tree.
// int verticalWidth(Node* root)
// {
//     st.clear();
//     calchd(root,0);

//     return st.size();
// }

// T.C :O(N)
// S.C: O(N)

int main(){

    return 0;
}
