#include <iostream>
using namespace std;

/*
 *
 *   Learning: Here I have got and idea like how can I use the concept of binary search on the bst. so if I can do something in binary search, so in bst
 *
 */

int floor(Node *root, int x)
{
    // Code here

    int floor = -1;

    while (root)
    {

        if (root->data <= x)
        {
            floor = root->data;
            root = root->right;
        }
        else
        {
            root = root->left;
        }
    }

    return floor;
}

int main()
{

    return 0;
}
