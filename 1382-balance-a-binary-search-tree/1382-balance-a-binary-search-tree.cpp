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
    vector<int>vec;
    void LNR(TreeNode* root) {
        if (root) {
            LNR(root->left);
            vec.push_back(root->val);
            LNR(root->right);
        }
    }
    TreeNode* makeBalanceTree(int left, int right) {
        if (left <= right) {
            int mid = left + (right - left) / 2;
            TreeNode* cur = new TreeNode(vec[mid]);
            cur->left = makeBalanceTree(left, mid - 1);
            cur->right = makeBalanceTree(mid + 1, right);
            return cur;
        }
        return nullptr;
    }
    TreeNode* balanceBST(TreeNode* root) {
        vec.resize(0);
        LNR(root);
        return makeBalanceTree(0, vec.size() - 1);
    }
};