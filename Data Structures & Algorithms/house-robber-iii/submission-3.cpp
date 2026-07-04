/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    unordered_map<TreeNode* , int> m;
    int rob(TreeNode* root) {
        if (!root)
            return 0;
        if (m[root] != 0) return m[root];
        int sum1 = 0, sum2 = 0;
        if (root->left)
            sum1 = (rob(root->left->right) + rob(root->left->left));
        if (root->right)
            sum2 = (rob(root->right->right) + rob(root->right->left));
        return m[root] = max(root->val + sum1 + sum2, rob(root->left) + rob(root->right));
    }
};