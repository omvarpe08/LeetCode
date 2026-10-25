/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {

        while(root != NULL && root->val != val) {
            root = val < root->val ? root->left : root->right;
        }
        return root;
    }
};

//here u can see u are traveling somewhere around height of tree or less than that & we know for BST height is mostly log2 N thus,

//TC = O(Log2 N)
//SC = O(1)