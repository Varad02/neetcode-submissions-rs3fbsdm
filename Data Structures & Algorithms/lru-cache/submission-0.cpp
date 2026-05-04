class Node {
public:
    int key;
    int val;
    Node* prev;
    Node* next;

    Node(int k, int v) : key(k), val(v), prev(nullptr), next(nullptr) {}
};

class LRUCache {
public:
    int cap;
    unordered_map<int, Node*> cache;
    Node* head;
    Node* tail;
    LRUCache(int capacity) {
        cap = capacity;
        head = new Node(0, 0);
        tail = new Node(0, 0);
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        if (cache.find(key) != cache.end()){
            moveFront(key);
            return cache[key]->val;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if (cache.find(key) != cache.end()) {
            remove(cache[key]);
            delete cache[key];
        }
        cache[key] = new Node(key, value);
        addFront(key);
        if ((int)cache.size() > cap) {
            Node* lru = tail->prev;
            int k = lru->key;
            remove(lru);
            cache.erase(k);
            delete lru;
        }
    }

    void moveFront(int key) {
        cache[key]->prev->next = cache[key]->next;
        cache[key]->next->prev = cache[key]->prev;
        cache[key]->next = head->next;
        cache[key]->prev = head;
        head->next->prev = cache[key];
        head->next = cache[key];
    }

    void addFront(int key) {
        cache[key]->next = head->next;
        cache[key]->prev = head;
        head->next->prev = cache[key];
        head->next = cache[key];
    }

    void remove(Node* node) {
        Node* prev = node->prev;
        Node* nxt = node->next;
        prev->next = nxt;
        nxt->prev = prev;
    }
};
