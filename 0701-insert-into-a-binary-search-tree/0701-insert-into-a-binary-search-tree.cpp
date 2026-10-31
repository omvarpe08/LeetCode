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
    TreeNode* insertIntoBST(TreeNode* root, int val) {

        TreeNode* temp = root;
        TreeNode* prev;

        if(temp == NULL) {
            return new TreeNode(val);
        }

        while(temp != NULL) {
            if(temp->val < val ) {
                prev = temp;
                temp = temp->right;

                if(temp == NULL) {
                    TreeNode* newNode = new TreeNode(val);
                    prev->right = newNode;
                }
            }

            else {
                prev = temp;
                temp = temp->left;

                if(temp == NULL) {
                    TreeNode* newNode = new TreeNode(val);
                    prev->left = newNode;
                }
            }

        }
        return root;


    }
};