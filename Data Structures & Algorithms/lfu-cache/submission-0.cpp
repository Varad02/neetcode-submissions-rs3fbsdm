class Node {
public:
    int val;
    Node *next, *prev;
    Node(int val) {
        this->val = val;
        next = nullptr;
        prev = nullptr;
    }
};

class DLL {
public:
    Node *head, *tail;
    DLL() {
        head = new Node(-1);
        tail = new Node(-1);
        head->next = tail;
        tail->prev = head;
    }
    bool isEmpty() { return head->next == tail; }
    void insert(Node* node) {
        head->next->prev = node;
        node->next = head->next;
        node->prev = head;
        head->next = node;
    }
    void deleteNode(Node* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }
    int deleteTail() {
        if (isEmpty())
            return -1;
        Node* last = tail->prev;
        int val = last->val;
        last->prev->next = tail;
        tail->prev = last->prev;
        return val;
    }
};

class LFUCache {
public:
    int capacity;
    int minF;
    unordered_map<int, int> freq;
    unordered_map<int, DLL*> freqDLL;
    unordered_map<int, int> um;
    unordered_map<int, Node*> cache;
    LFUCache(int capacity) {
        this->capacity = capacity;
        minF = INT_MAX;
    }

    int get(int key) {
        if (um.find(key) == um.end())
            return -1;
        touch(key);
        return um[key];
    }

    void put(int key, int value) {
        if (um.find(key) != um.end()) {
            um[key] = value;
            touch(key);
            return;
        }
        if (um.size() == capacity) {
            int old = freqDLL[minF]->deleteTail();
            freq.erase(old);
            um.erase(old);
            cache.erase(old);
        }
        um[key] = value;
        freq[key] = 1;
        minF = 1;
        Node* node = new Node(key);
        cache[key] = node;
        if (freqDLL[1] == nullptr)
            freqDLL[1] = new DLL();
        freqDLL[1]->insert(node);
    }

    void touch(int key) {
        int f = ++freq[key];
        Node* node = cache[key];
        freqDLL[f - 1]->deleteNode(node);
        if (freqDLL[f] == nullptr)
            freqDLL[f] = new DLL();
        freqDLL[f]->insert(node);
        if (freqDLL[f - 1]->isEmpty() && minF == f - 1)
            minF = f;
    }
};