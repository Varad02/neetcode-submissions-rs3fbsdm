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
    int goodNodes(TreeNode* root) {
        return 1 + util(root->left, root->val) + util(root->right, root->val);
    }

    int util(TreeNode* root, int maxVal) {
        if (!root) return 0;
        if (root->val >= maxVal) {
            return 1 + util(root->left, root->val) + util(root->right, root->val);
        }
        return util(root->left, maxVal)+util(root->right, maxVal);
    }
};
