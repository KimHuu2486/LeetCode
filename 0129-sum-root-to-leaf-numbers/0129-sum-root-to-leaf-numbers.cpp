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
    void solve(TreeNode* root, int num, int& total){
        if (!root) return;
        num = num*10 + root->val;
        if (!root->left && !root->right){
            total+=num;
            return;
        }
        solve(root->left, num, total);
        solve(root->right, num, total);
    }
    int sumNumbers(TreeNode* root) {
        int total = 0;
        int num = 0;
        solve(root, num, total);
        return total;
    }
};