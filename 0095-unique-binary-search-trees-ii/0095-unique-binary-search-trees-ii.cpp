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
    vector<TreeNode*>solve(int start, int end){
        vector<TreeNode*>trees;
        if (end<start){
            trees.push_back(NULL);
            return trees;
        }
        for (int i = start; i<=end; i++){
            vector<TreeNode*>leftTree = solve(start, i - 1);
            vector<TreeNode*>rightTree = solve(i+1, end);
            for (TreeNode* left: leftTree){
                for (TreeNode* right: rightTree){
                    TreeNode* root = new TreeNode(i);
                    root->left = left;
                    root->right = right;
                    trees.push_back(root);
                }
            }
        }
        return trees;
    }
    vector<TreeNode*> generateTrees(int n) {
        return solve(1, n);
    }
};