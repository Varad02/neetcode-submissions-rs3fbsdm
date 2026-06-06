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
    int res = INT_MIN;
    int maxPathSum(TreeNode* root) {
        return max(res, util(root));
    }

    int util(TreeNode* root) {
        int left = 0, right = 0;
        if(root->left)
        left = util(root->left);
        if(root->right)
        right = util(root->right);
        res = max(max(max(res, left+right+root->val), root->val), max(left, right) + root->val);
        return max((max(left, right) + root->val), root->val);
    }
};
