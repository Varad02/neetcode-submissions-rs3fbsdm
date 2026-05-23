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
    vector<int> rightSideView(TreeNode* root) {
        if (!root) return {};
        queue<TreeNode*> st;
        st.push(root);
        vector<int> res;
        while (!st.empty()) {
            int n = st.size();
            res.push_back(st.front()->val);
            for (int i = 0; i < n; i++) {
                TreeNode* node = st.front();
                if (node->right) st.push(node->right);
                if (node->left) st.push(node->left);
                st.pop();
            }
        }
        return res;
    }
};
