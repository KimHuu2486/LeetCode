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
    int minDepth(TreeNode* root) {
        if (!root) return 0;
        queue<pair<TreeNode*, int>>q;
        q.push({root, 1});
        while (!q.empty()){
            auto [Node, depth] = q.front();
            q.pop();
            if (!Node->left && !Node->right) return depth;
            if (Node->left){
                q.push({Node->left, depth+1});
            }
            if (Node->right){
                q.push({Node->right, depth+1});
            }
        }
        return 0;
    }
};