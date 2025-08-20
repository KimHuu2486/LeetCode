class Node {
public:
    int key;
    int val;
    Node* prev;
    Node* next;
    Node(int key, int val) : key(key), val(val), prev(nullptr), next(nullptr) {}
};
class LRUCache {
private:
    int cap;
    unordered_map<int, Node*> cache;
    Node* oldest;
    Node* latest;

public:
    LRUCache(int capacity) : cap(capacity) {
        oldest = new Node(0, 0);
        latest = new Node(0, 0);
        oldest->next = latest;
        latest->prev = oldest;
    }
    void insert(Node* node) {
        Node* prev = latest->prev;
        prev->next = node;
        node->prev = prev;
        node->next = latest;
        latest->prev = node;
    }
    void remove(Node* node) {
        Node* prev = node->prev;
        Node* next = node->next;
        prev->next = next;
        next->prev = prev;
    }
    int get(int key) {
        if (cache.find(key) != cache.end()) {
            Node* cur = cache[key];
            remove(cur);
            insert(cur);
            return cur->val;
        }
        return -1;
    }
    void put(int key, int value) {
        if (cache.find(key) != cache.end()) {
            remove(cache[key]);
        }
        Node* newNode = new Node(key, value);
        cache[key] = newNode;
        insert(newNode);
        if (cache.size() > cap) {
            Node* lru = oldest->next;
            remove(lru);
            cache.erase(lru->key);
            delete lru;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */