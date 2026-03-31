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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int, int> m;
        for (int i = 0; i < inorder.size(); i++) m[inorder[i]] = i;
        return util (preorder, m, 0, inorder.size()-1, 0);
    }

    TreeNode* util(vector<int>& p, unordered_map<int, int> &m, int l, int r, int i) {
        int val = p[i];
        int ind = m[p[i]];
        TreeNode* root = new TreeNode(val);
        if (l<ind) root->left = util (p, m, l, ind-1, i+1);
        if (r>ind) root->right = util (p, m, ind+1, r, i+ind-l+1);
        return root;
    }
};
