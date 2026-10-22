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

        int left = maxDepth(root->left);
        int right = maxDepth(root->right);

        return 1 + max(left, right);
    }

    bool isBalanced(TreeNode* root) {
        if(root == NULL) return true;
        
        int hl = maxDepth(root->left);
        int hr = maxDepth(root->right);

        if(abs(hl-hr) > 1 ) {
            return false;
        }

        return isBalanced(root->left) && isBalanced(root->right);

    }
};

//TC: O(N^2) in the worst case, because maxDepth() is repeatedly called at each node.
//SC: O(H) auxiliary space for recursion, where \(H\) is the tree height. 
//worst case : Degenerate (Skewed) Binary Tree O(N), Best Case : balanced tree O(log N).
