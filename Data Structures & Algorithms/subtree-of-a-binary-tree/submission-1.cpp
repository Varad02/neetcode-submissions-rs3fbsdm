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
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if (!root) return false;
        if (root->val == subRoot->val)
            return isSameTree(root, subRoot) or isSubtree(root->left, subRoot) or
                   isSubtree(root->right, subRoot);
        return isSubtree(root->left, subRoot) or isSubtree(root->right, subRoot);
    }
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (!p and !q) return true;
        if ((p and !q) or (q and !p)) return false;
        if (p->val != q->val) return false;
        return isSameTree(p->right, q->right) and isSameTree(q->left, p->left);
    }
};
