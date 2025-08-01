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
    void LNR(TreeNode* root, vector<int>& value) {
        if (root) {
            LNR(root->left, value);
            value.push_back(root->val);
            LNR(root->right, value);
        }
    }
    bool isValidBST(TreeNode* root) { 
        vector<int> value; 
        LNR(root, value);
        for (int i = 0; i<value.size()-1; i++){
            if (value[i]>=value[i+1]){
                return false;
            }
        }
        return true;
    }
};