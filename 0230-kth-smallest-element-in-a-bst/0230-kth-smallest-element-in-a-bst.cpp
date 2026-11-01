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
    int kthSmallest(TreeNode* root, int k) {
        int ans;
        inorder(root, k, ans);
        return ans;
    }

    void inorder(TreeNode* root , int& cnt , int& ans) {
        if(root == NULL || cnt==0) {
            return;
        }

        inorder(root->left , cnt , ans);
        if(cnt == 0) return;
        ans = root->val;
        cnt--;
        
        inorder(root->right , cnt ,ans);
    }
};