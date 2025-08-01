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
        if (!root) return;
        LNR(root->left, vec);
        vec.push_back(root->val);
        LNR(root->right, vec);
    }
    int minDiffInBST(TreeNode* root) {
        vector<int>vec;
        LNR(root, vec);
        int res = INT_MAX;
        for (int i = 0; i<vec.size()-1; i++){
            res = min (res, vec[i+1]- vec[i]);
        }
        return res;
    }
};