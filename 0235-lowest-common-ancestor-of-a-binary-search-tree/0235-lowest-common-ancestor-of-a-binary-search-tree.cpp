class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {

        while(root != NULL) {
            if(p->val < root->val && q->val < root->val) {
                root = root->left;
            }
            else if(p->val > root->val && q->val > root->val) {
                root = root->right;
            }
            else {
                return root;
            }
        }

        return NULL;
    }
};

//TC: O(H) – H is the height of the BST.
//SC: O(1) – No extra space.