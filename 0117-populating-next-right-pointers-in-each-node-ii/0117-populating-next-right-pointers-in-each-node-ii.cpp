/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if (!root)
            return root;
        Node* cur = root;
        Node* nextHead = nullptr;
        Node* rightMost = nullptr;
        while (cur) {
            if (cur->left) {
                if (!nextHead) {
                    nextHead = cur->left;
                }
                if (rightMost) {
                    rightMost->next = cur->left;
                }
                rightMost = cur->left;
            }
            if (cur->right) {
                if (!nextHead) {
                    nextHead = cur->right;
                }
                if (rightMost) {
                    rightMost->next = cur->right;
                }
                rightMost = cur->right;
            }
            cur = cur->next;
        }
        connect(nextHead);
        return root;
    }
};