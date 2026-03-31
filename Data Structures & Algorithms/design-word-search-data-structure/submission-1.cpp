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

class WordDictionary {
public:
    TrieNode* root;
    WordDictionary() {
        root = new TrieNode();
    }
    
    void addWord(string word) {
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
        return util(word, 0, root);
    }

    bool util(string word, int i, TrieNode* curr) {
        if (i==word.size() and !curr->isLeaf) return false;
        if (i==word.size()) return true;
        if (word[i]!='.') {
            if (!curr->children[word[i]-'a']) return false;
            return util (word, i+1, curr->children[word[i]-'a']);
        } else {
            bool f = false;
            for (auto j: curr->children) {
                if (j)
                f = f or util(word, i+1, j);
            }
            return f;
        }
    }
};
