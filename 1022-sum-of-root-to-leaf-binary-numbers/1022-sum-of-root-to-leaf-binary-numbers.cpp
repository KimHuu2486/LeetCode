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
    int LNR(TreeNode* cur, int num) {
        if (!cur) return num;
        num <<= 1;
        num += cur->val;
        if (!cur->left && !cur->right) {
            return num;
        }
        if (!cur->left) {
            return LNR(cur->right, num);
        }
        if (!cur->right) {
            return LNR(cur->left, num);
        }
        return LNR(cur->left, num) + LNR(cur->right, num);
    }
    int sumRootToLeaf(TreeNode* root) {
        return LNR(root, 0);
    }
};