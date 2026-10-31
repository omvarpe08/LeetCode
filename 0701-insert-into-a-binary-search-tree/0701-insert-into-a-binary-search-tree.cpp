class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        TreeNode* newNode = new TreeNode(val);

        if(root == NULL) {
            return newNode;
        }

        TreeNode* curr = root;

        while(true) {
            if(val < curr->val) {
                if(curr->left == NULL) {
                    curr->left = newNode;
                    break;
                }
                curr = curr->left;
            }
            else {
                if(curr->right == NULL) {
                    curr->right = newNode;
                    break;
                }
                curr = curr->right;
            }
        }

        return root;
    }
};

//here u are travelling equal to height of tree & we know for BST height is mostly log2 N thus,

//TC = O(Log2 N)
//SC = O(1)