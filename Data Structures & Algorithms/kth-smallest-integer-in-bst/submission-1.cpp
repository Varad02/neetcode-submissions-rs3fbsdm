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
    int val, cnt;

    void util(TreeNode* root, int &k) {
        if (!root) return;
        util(root->left, k);
        cnt++;
        if (cnt == k) {
            val = root->val;
            return;
        }
        util(root->right, k);

    }
    int kthSmallest(TreeNode* root, int k) {
        cnt = 0;
        util(root, k);
        return val;
    }
};
