/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    pair<int, TreeNode*> dfs(TreeNode* node) {
        if (!node) {
            return {0, nullptr};
        }
        auto L = dfs(node->left);
        auto R = dfs(node->right);
        if (L.first == R.first) {
            return {L.first + 1, node};
        }
        else if (L.first > R.first) {
            return {L.first + 1, L.second};
        }
        else {
            return {R.first + 1, R.second};
        }
    }
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        return dfs(root).second;    
    }
};