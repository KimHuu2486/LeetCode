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
    int sum = 0;
    void RNL(TreeNode* root){
        if (!root) return;
        RNL(root->right);
        root->val += sum;
        sum = root->val;
        RNL(root->left);
    }
    TreeNode* convertBST(TreeNode* root) {
        RNL(root);
        return root;
    }
};