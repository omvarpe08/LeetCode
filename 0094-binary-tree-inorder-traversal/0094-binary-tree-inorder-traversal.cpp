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
    vector<int> inorderTraversal(TreeNode* root) {
        
        inorderTrav(root);
        return inorder;

    }

    vector<int> inorder;

    void inorderTrav(TreeNode* root) {

        if(root==NULL) return;

        inorderTrav(root->left);
        inorder.push_back(root->val);
        inorderTrav(root->right);

    }
};