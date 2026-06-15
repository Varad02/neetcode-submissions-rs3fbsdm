/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    string a = to_string(INT_MIN) + " ";
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string res = "";
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();
            res += node ? to_string(node->val) + " " : a;
            if (node) {
                q.push(node->left);
                q.push(node->right);
            }
        }
        return res;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        istringstream iss(data);
        vector<int> vals;
        string word;
        while (iss >> word) {
            vals.push_back(stoi(word));
        }
        if (vals[0] == INT_MIN)
            return nullptr;
        TreeNode* root = new TreeNode(vals[0]);
        queue<TreeNode*> q;
        q.push(root);
        int i = 1;
        while (!q.empty() and i < vals.size()) {
            TreeNode* node = q.front();
            q.pop();
            if (vals[i] != INT_MIN and node) {
                node->left = new TreeNode(vals[i]);
                q.push(node->left);
            }
            if (!node)
                q.push(node);
            i++;
            if (vals[i] != INT_MIN and node and i < vals.size()) {
                node->right = new TreeNode(vals[i]);
                q.push(node->right);
            }
            if (!node)
                q.push(node);
            i++;
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));