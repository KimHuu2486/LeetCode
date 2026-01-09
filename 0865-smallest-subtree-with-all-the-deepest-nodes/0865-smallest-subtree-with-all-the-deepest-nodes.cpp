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
private:
    int maxLen = 0;
    vector<vector<TreeNode*>>Paths;
public:
    void dfs(TreeNode* node, vector<TreeNode*>& path) {
        path.push_back(node);
        if (!node->left && !node->right) {
            Paths.push_back(path);
            maxLen = max(maxLen, (int)path.size());
            path.pop_back();
            return;
        }
        if (node->left) {
            dfs(node->left, path);
        }
        if (node->right) {
            dfs(node->right, path);
        }
        path.pop_back();
    }
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        vector<TreeNode*>path;
        dfs(root, path);
        int start = 0;
        int n = Paths.size();

        for (int i = 0; i < n; i++) {
            if (maxLen == Paths[i].size()) {
                start = i;
                break;
            }
        }

        for (int j = 0; j < maxLen; j++) {
            TreeNode* cur = Paths[start][j];
            for (int i = start + 1; i < n; i++) {
                if (maxLen == Paths[i].size()) {
                    if (cur != Paths[i][j]) {
                        return Paths[i][j - 1];
                    }
                }
            }
        }

        return Paths[start][maxLen - 1];
    }
};