class Solution {
public:
    int ans = -1;

    void inorder(TreeNode* root, int &k) {
        if (root == NULL) {
            return;
        }

        inorder(root->left, k);

        k--;

        if (k == 0) {
            ans = root->val;
            return;
        }

        inorder(root->right, k);
    }

    int kthSmallest(TreeNode* root, int k) {
        inorder(root, k);
        return ans;
    }
};

//if we dont use int &k and use int k then Changes made to k inside the left recursive call will NOT update the parent's k. thus we use int &k.

//TC = O(N)  ...N : num of node
//              In worst case we are travesing at each node thus O(N);

//SC = O(H)  ..auxiliary space for the recursion stack, where H is the tree height;                        
//worst case : Degenerate (Skewed) Binary Tree O(N), Best Case : balanced tree O(log N).

//u might think that recursion stack should O(N) but no bcoz the key point is that stack space is the number of calls waiting at the same time & it depends on the tree's height H, not the total number of nodes N.