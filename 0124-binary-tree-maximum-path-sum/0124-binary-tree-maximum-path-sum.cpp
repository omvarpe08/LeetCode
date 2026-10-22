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
    int maxSum(TreeNode* root, int &sum) {

        if(root == NULL){
            return 0;
        }

        int leftSum = max(0 , maxSum(root->left, sum));
        int rightSum = max(0 , maxSum(root->right, sum));
        sum = max(sum , leftSum + rightSum + root->val);

        return max(leftSum + root->val , rightSum + root->val);
    }

    int maxPathSum(TreeNode* root) {
        int s = INT_MIN;
        maxSum(root , s);
        return s;
    }
};

//TC = O(N)   ...travesing all nodes

//SC: O(H) auxiliary space for recursion, where H is the tree height. 
//worst case : Degenerate (Skewed) Binary Tree O(N), Best Case : balanced tree O(log N).