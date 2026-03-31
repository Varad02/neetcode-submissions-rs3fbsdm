class TrieNode {
public:
    TrieNode* children[26];
    bool isLeaf;

    TrieNode() {
        isLeaf = false;
        for (int i = 0; i < 26; i++) {
            children[i] = nullptr;
        }
    }
};

class PrefixTree {
public:
    TrieNode* root;
    PrefixTree() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode* curr = root;
        for (auto l: word) {
            if(!curr->children[l-'a']) {
                curr->children[l-'a'] = new TrieNode();
            }
            curr = curr->children[l-'a'];
        }
        curr->isLeaf = true;
    }
    
    bool search(string word) {
        TrieNode* curr = root;
        for (auto l: word) {
            if(curr->children[l-'a']) {
                curr=curr->children[l-'a'];
            }
        }
        return curr->isLeaf;
    }
    
    bool startsWith(string prefix) {
        TrieNode* curr = root;
        for (auto l: prefix) {
            if(curr->children[l-'a']) {
                curr=curr->children[l-'a'];
            }
            else {
                return false;
            }
        }
        return true;
    }
};
