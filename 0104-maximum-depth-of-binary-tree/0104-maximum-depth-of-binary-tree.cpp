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
};

//we can also solve this question by level order traversal

//TC = O(N)  ..we are visiting each node & we cant improve it bcoz we had to visit each node

//SC = O(H)  ...recursion stack, where H is the tree height; worst case O(N), balanced tree O(log N).

//u might think that recursion stack should O(N) but no bcoz the key point is that stack space is the number of calls waiting at the same time & it depends on the tree's height H, not the total number of nodes N.