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

    // void preorder(TreeNode* root, vector<int>& ans) {
    //     if(root == NULL) {
    //         return;
    //     }
    //     ans.push_back(root->val);
    //     preorder(root->left , ans);
    //     preorder(root->right , ans);
    // }
    TreeNode* searchBST(TreeNode* root, int val) {
        TreeNode* temp = root;

        while(temp != NULL) {
            if(temp->val == val) {
                return temp;
            }   
            else if(temp->val > val) {
                temp = temp->left;
            }
            else if(temp->val < val) {
                temp = temp->right;
            }
        }
        return NULL;
    }
};