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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        
        if(root == NULL) {
            return ans;
        }

        queue<TreeNode*> q;

        q.push(root);

        while(!q.empty()) {
            int n = q.size();
            vector<int> level;

            for(int i=0; i<n; i++) {
                TreeNode* Node = q.front();
                q.pop();

                if(Node->left != NULL) {
                    q.push(Node->left);
                }

                if(Node->right != NULL) {
                    q.push(Node->right);
                }
                
                level.push_back(Node->val);
            }

            ans.push_back(level);
        }

        return ans;
    }
};

//TC = O(N)  ...N : num of node
//              we are travesing at each node thus O(N);

//SC = O(N)  ...Queue (in worst case we are storing N node in queue thus O(N))
//what about vector<vector<int>> ans - generally we wont consider it bcoz it is something which we are using for retruning ans.