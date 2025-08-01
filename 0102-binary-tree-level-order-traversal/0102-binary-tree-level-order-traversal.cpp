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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (!root)
            return {};
        queue<TreeNode*> qu;
        qu.push(root);
        vector<vector<int>> ans;
        while (!qu.empty()) {
            int n = qu.size();
            vector<int> level;
            for (int i = 1; i <= n; i++) {
                TreeNode* t = qu.front();
                qu.pop();
                if (t) {
                    level.push_back(t->val);
                    if (t->left) {
                        qu.push(t->left);
                    }
                    if (t->right) {
                        qu.push(t->right);
                    }
                }
            }
            ans.push_back(level);
        }
        return ans;
    }
};