/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    unordered_map<int, Node*> s;
    Node* cloneGraph(Node* node) {
        if(!node) return nullptr;
        return util(node);
    }

    Node* util(Node* node) {
        if(s.find(node->val)!=s.end()) return s[node->val];
        Node* newNode = new Node(node->val);
        s[node->val] = newNode;
        for (auto i: node->neighbors) {
            Node* newNN = new Node(i->val);
            newNode->neighbors.push_back(util(i));
        }
        return newNode;
    }
};
