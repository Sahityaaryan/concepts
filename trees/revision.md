
# Must remeber how to get the parent of a node and the left and right when an array is given

1. parent = arr[(i-1)/2];
2. left = arr[(2*i + 1)];
3. right = arr[(2*i + 2)]
4. In the method of queue while traversing the nodes of a tree (q.size() == number of nodes at that level)
5. Most of the Trees questions can be solved either by traversals or somehow fitting the above index based approach.


# BST

1. In a valid Binary Search Tree all keys are unique.
2. The inorder traversal of the bst represents a sorted array so if you want to do some to solve some question using the sorted order try it using the inorder traversal.

3. A valid BST is defined as follows:

    - The left subtree of a node contains only nodes with keys less than the node's key.
    - The right subtree of a node contains only nodes with keys greater than the node's key.
    - Both the left and right subtrees must also be binary search trees.

 4. There is one problem in my every attempt of solving bst problems is that I am ignoring the fact that it is not a simple tree it's inorder has the ascending order sorting, if it think to find an answer by leveraging the ascending order sorting the answer should have been solved with much leser time complexity
