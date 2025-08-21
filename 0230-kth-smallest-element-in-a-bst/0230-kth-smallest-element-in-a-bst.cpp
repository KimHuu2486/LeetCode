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
    int ans, count = 0;
    void LNR(TreeNode* root, int k) {
        if (!root || count >= k)
            return;
        LNR(root->left, k);
        count++;
        if (count == k){
            ans = root->val;
            return;
        }
        LNR(root->right, k);
    }
    int kthSmallest(TreeNode* root, int k) {
        LNR(root, k);
        return ans;
    }
};