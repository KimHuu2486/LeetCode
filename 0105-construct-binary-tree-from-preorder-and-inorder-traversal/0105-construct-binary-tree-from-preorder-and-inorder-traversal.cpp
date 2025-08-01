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
    TreeNode* solve(vector<int>& preorder, vector<int>& inorder,
                    pair<int, int> pre, pair<int, int> in) {
        if (pre.first > pre.second || in.first > in.second)
            return nullptr;
        TreeNode* root = new TreeNode;
        root->val = preorder[pre.first];
        if (pre.first == pre.second) {
            root->left = NULL;
            root->right = NULL;
            return root;
        }
        int i = in.first;
        for (i; i <= in.second; i++) {
            if (inorder[i] == root->val)
                break;
        }
        int mid = i;
        int leftSize = mid - in.first;
        pair<int, int> leftPre = {pre.first + 1, pre.first + leftSize};
        pair<int, int> rightPre = {pre.first + leftSize + 1, pre.second};
        pair<int, int> leftIn = {in.first, mid - 1};
        pair<int, int> rightIn = {mid + 1, in.second};
        root->left = solve(preorder, inorder, leftPre, leftIn);
        root->right = solve(preorder, inorder, rightPre, rightIn);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();
        return solve(preorder, inorder, {0, n - 1}, {0, n - 1});
    }
};