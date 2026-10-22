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
        int cnt = 0;
        if(root == NULL) {
            return cnt;
        }

        queue<TreeNode*> q;

        q.push(root);

        while(!q.empty()) {
            int n = q.size();

            for(int i=0; i<n; i++) {
                TreeNode* Node = q.front();
                q.pop();

                if(Node->left != NULL) {
                    q.push(Node->left);
                }

                if(Node->right != NULL) {
                    q.push(Node->right);
                }
            
            }
            cnt++;

        }

        return cnt;
    }
};