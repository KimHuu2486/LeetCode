class WordDictionary {
private:
    struct Node {
        Node* child[26];
        bool isEnd;
        Node() {
            fill(child, child + 26, nullptr);
            isEnd = false;
        }
    };
    Node* root = new Node();
    bool solveSearch(const string& word, Node* cur, int idx) {
        if (!cur)
            return false;
        if (idx == (int)word.size())
            return cur->isEnd;

        if (word[idx] == '.') {
            for (Node* nxt : cur->child) {
                if (solveSearch(word, nxt, idx + 1))
                    return true;
            }
            return false;
        } else {
            int k = word[idx] - 'a';
            return solveSearch(word, cur->child[k], idx + 1);
        }
    };

public:
    WordDictionary() {}

    void addWord(const string& word) {
        Node* node = root;
        for (char c : word) {
            int k = c - 'a';
            if (!node->child[k])
                node->child[k] = new Node();
            node = node->child[k];
        }
        node->isEnd = true;
    }

    bool search(const string& word) {
        return solveSearch(word, root, 0);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */