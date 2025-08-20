/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    int height(TreeNode* root) {
        int cnt = 0;
        while (root) {
            cnt++;
            root = root->left;
        }
        return cnt;
    }
    int countNodes(TreeNode* root) {
        if (!root)
            return 0;
        int hl = height(root->left);
        int hr = height(root->right);
        if (hl == hr) {
            return (1 << hl) + countNodes(root->right);
        } else {
            return (1 << hr) + countNodes(root->left);
        }
    }
};