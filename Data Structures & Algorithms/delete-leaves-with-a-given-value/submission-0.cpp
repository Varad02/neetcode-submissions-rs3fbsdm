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
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        if(!root) return root;
        util(root->left, root, target, 'l');
        util(root->right, root, target, 'r');
        if (!root->left and !root->right and root->val == target) return nullptr;
        return root;
    }

    void util(TreeNode* root, TreeNode* parent, int target, char child) {
        if (!root) return;
        if (!root->left and !root->right and root->val == target) {
            if (child == 'l') parent->left = nullptr;
            else parent->right = nullptr;
            return;
        }
        util(root->left, root, target, 'l');
        util(root->right, root, target, 'r');
        if (!root->left and !root->right and root->val == target) {
            if (child == 'l') parent->left = nullptr;
            else parent->right = nullptr;
        }
        return;
    }
};