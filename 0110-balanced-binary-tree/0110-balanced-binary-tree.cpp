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
    int maxDepth(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }

        int leftHeight = maxDepth(root->left);
        int rightHeight = maxDepth(root->right);

        if(leftHeight == -1 || rightHeight == -1) {
            return -1;
        }

        if(abs(leftHeight - rightHeight) > 1) {
            return -1;
        }

        return 1 + max(leftHeight, rightHeight);
    }

    bool isBalanced(TreeNode* root) {
        return maxDepth(root) != -1;

    }
};

//Optimal

//TC = O(N)   ...travesing all nodes

//SC: O(H) auxiliary space for recursion, where \(H\) is the tree height. 
//worst case : Degenerate (Skewed) Binary Tree O(N), Best Case : balanced tree O(log N).


