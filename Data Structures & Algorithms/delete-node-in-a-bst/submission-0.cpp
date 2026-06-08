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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (root == NULL)
            return root;

        if (root->val > key) {
            root->left = deleteNode(root->left, key);
            return root;
        }

        else if (root->val < key) {
            root->right = deleteNode(root->right, key);
            return root;
        }

        if (!root->left and !root->right) {
            delete root;
            return NULL;
        }
        if (root->left == NULL) {
            TreeNode* p = root->right;
            delete root;
            return p;
        }

        if (root->right == NULL) {
            TreeNode* p = root->left;
            delete root;
            return p;
        }
        TreeNode* p = root->left;
        TreeNode* q;
        while (p->right != NULL) {
            q = p;
            p = p->right;
        }
        if (p == root->left) {

            p->right = root->right;
            return p;
        }
        root->val = p->val;
        q->right = p->left;
        delete p;
        return root;
    }
};