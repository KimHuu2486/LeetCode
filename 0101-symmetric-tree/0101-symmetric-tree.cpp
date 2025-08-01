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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (!p && !q) return 1;
        if (p && q){
            return p->val == q->val && isSameTree(p->left, q->right) && isSameTree(p->right, q->left);
        }
        return 0;
    }
    bool isSymmetric(TreeNode* root) {
        if (!root->left && !root->right) return 1;
        return isSameTree(root->left, root->right);
    }
};