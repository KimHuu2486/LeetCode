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
    int maxLevelSum(TreeNode* root) {
        queue<TreeNode*>q;
        q.push(root);
        int level = INT_MIN, sumLevel = INT_MIN;
        int curLevel = 1;

        while (!q.empty()) {
            int n = q.size();
            int curSum = 0;
            for (int i = 0; i < n; i++) {
                TreeNode* cur = q.front();
                q.pop();
                curSum += cur->val;
                if (cur->left) {
                    q.push(cur->left);
                }
                if (cur->right) {
                    q.push(cur->right);
                }
            }
            if (sumLevel < curSum) {
                level = curLevel;
                sumLevel = curSum;
            }
            curLevel++;
        }
        
        return level;
    }
};