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
    long long SUM = 0LL;
    long long ans = 0LL;
public:
    void dfs(TreeNode* cur) {
        if (cur) {
            dfs(cur->left);
            dfs(cur->right);
            SUM += cur->val;
        }
    }
    long long calSum(TreeNode* cur) {
        if (cur) {
            long long left = calSum(cur->left);
            long long right = calSum(cur->right);
            long long temp = left + right + cur->val;
            ans = max(ans, temp * (SUM - temp));
            return temp;
        }
        return 0;
    }
    int maxProduct(TreeNode* root) {
        dfs(root);
        calSum(root);
        return ans % 1000000007;
    }
};