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
        return util(root, INT_MIN);
    }

    int util(TreeNode* node, int parent) {
        int count = 0;
        if (parent <= node->val) count = 1;
        int maxx = max(parent, node->val);
        if (node->left) count+=util(node->left, maxx);
        if (node->right) count+=util(node->right, maxx);
        return count;
    }
};
