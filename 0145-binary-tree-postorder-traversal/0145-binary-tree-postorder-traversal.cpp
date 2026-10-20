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
    void postorder(TreeNode* root, vector<int>& ans) {
        if (root == NULL) {
            return;
        }

        postorder(root->left, ans);
        postorder(root->right, ans);
        ans.push_back(root->val);
    }

    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        postorder(root, ans);
        return ans;
    }
};



//TC = O(N)  ...N : num of node
//              we are travesing at each node thus O(N);

//SC = O(N)   ...recursion stack bcoz funcn's are ging to wait in stack to be completed & O(N) bcoz we calculate TC & SC for worst case & in worst case N node is going to wait in stack to be completed. 
//i.e for Degenerate (Skewed) Binary Tree