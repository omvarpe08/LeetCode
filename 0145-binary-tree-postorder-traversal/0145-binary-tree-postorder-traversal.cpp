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

//SC = O(H)  ..auxiliary space for the recursion stack, where H is the tree height;                        worst case : Degenerate (Skewed) Binary Tree O(N), Best Case : balanced tree O(log N).

//u might think that recursion stack should O(N) but no bcoz the key point is that stack space is the number of calls waiting at the same time & it depends on the tree's height H, not the total number of nodes N.

//what about vector<int> ans - generally we wont consider it bcoz it is something which we are using for retruning ans.
//Output space: O(N) ...ans vector.