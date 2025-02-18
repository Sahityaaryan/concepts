

typedef TreeNode tn;
class Solution
{
public:
    tn *find_key(tn *root, int key, tn *&parent, bool& isLeft)
    {

        if (!root)
            return nullptr;
        if (root->val == key){
            isLeft = false; 
            return root;
        }
           
        tn *left = find_key(root->left, key, root);
        if (left){
           isLeft = true;
            return left;
        }
        
        return find_key(root->right, key, parent);
    }

    TreeNode *deleteNode(TreeNode *root, int key)
    {
        // remove the desired element
        if (!root)
            return nullptr;
        tn *parent = nullptr;
        bool isLeft = false;
        tn *key_node = find_key(root, key, parent, isLeft);

        if (!key_node)
            return root;
        tn *left = key_node->left;

        if (parent)
        {
            if (left)
            {
                tn *right = key_node->right;

                if (right)
                {
                    while (left->right)
                    {
                        left = left->right;
                    }
                    left->right = right;
                }
                
                if(isLeft) parent->left = left;
                else parent->right = left;

            }
            else if (key_node->right)
            {
                 if(isLeft) parent->left = key_node->right;
                else parent->right = key_node->right;

            }
            else
            {
                if(isLeft) parent->left = nullptr;
                else parent->right = nullptr;
            }
        }
        else
        {
            tn *left = key_node->left;
            tn *right = key_node->right;

            if (left)
            {
                while (left->right)
                {
                    left = left->right;
                }
                left->right = right;
                return left;
            }
            else
            {
                return right;
            }
        }
        return root;
    }

    // reimplement the bst
}
;
