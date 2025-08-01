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
    void LNR(TreeNode* root, vector<int>&vec){
        if (root){
            LNR(root->left, vec);
            vec.push_back(root->val);
            LNR(root->right, vec);
        }
    }
    int countNodes(TreeNode* root) {
        vector<int>vec;
        LNR(root, vec);
        return vec.size();
    }
};