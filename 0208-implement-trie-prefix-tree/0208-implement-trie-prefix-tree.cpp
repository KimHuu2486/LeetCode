class Trie {
private:
    struct Node{
        Node* child[26];
        bool isEnd;
        Node(){
            fill(child, child + 26, nullptr);
            isEnd = false;
        }
    };
    Node* root = new Node();
public:
    Trie() {

    }
    
    void insert(const string& word) {
        Node* node = root;
        for (char c : word){
            int k = c - 'a';
            if (!node->child[k]) node->child[k] = new Node();
            node = node->child[k];
        }
        node->isEnd = true;
    }
    
    bool search(const string& word) {
        Node* node = root;
        for (char c : word){
            int k = c - 'a';
            if (!node->child[k]) return false;
            node = node->child[k];
        }
        return node->isEnd;
    }
    
    bool startsWith(const string& prefix) {
        Node* node = root;
        for (char c : prefix){
            int  k = c - 'a';
            if (!node->child[k]) return false;
            node = node->child[k];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */