class Solution {
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int i = 0;
        return build(preorder, i, LLONG_MAX);
    }

    TreeNode* build(vector<int>& preorder, int& i, long long bound) {
        if (i == preorder.size() || preorder[i] > bound) {
            return NULL;
        }

        TreeNode* root = new TreeNode(preorder[i++]);

        root->left = build(preorder, i, root->val);
        root->right = build(preorder, i, bound);

        return root;
    }
};

//TC = O(3N) = O(N)  ...bcoz visiting a element almost thrice in worst case
//SC = O(H) ...Recursion Stack