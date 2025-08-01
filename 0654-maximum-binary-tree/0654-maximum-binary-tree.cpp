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
    TreeNode* solve(vector<int>& nums, int start, int end) {
        if (start > end) return nullptr;

        int maxIdx = start;
        for (int i = start + 1; i <= end; ++i) {
            if (nums[i] > nums[maxIdx]) {
                maxIdx = i;
            }
        }

        TreeNode* root = new TreeNode(nums[maxIdx]);
        root->left = solve(nums, start, maxIdx - 1);
        root->right = solve(nums, maxIdx + 1, end);
        return root;
    }
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return solve(nums, 0, nums.size() - 1);
    }
};