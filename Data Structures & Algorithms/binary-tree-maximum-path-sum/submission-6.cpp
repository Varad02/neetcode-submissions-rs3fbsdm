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
    int ans = INT_MIN;
    int maxPathSum(TreeNode* root) {
        util(root);
        return ans;
    }

    int util(TreeNode* root) {
        int left = 0, right = 0;
        if(root->left)
        left = util(root->left);
        if(root->right)
        right = util(root->right);
        ans = max(max(root->val, max(root->val + left, root->val + right)), max(ans, left + root->val + right));
        return max(root->val, max(root->val + left, root->val + right));
    }
};
