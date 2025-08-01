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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>>ans;
        if (!root) return ans;
        queue<TreeNode*>q;
        q.push(root);
        bool leftToRight = 1;
        while(!q.empty()){
            int n = q.size();
            vector<int>vec;
            for (int i = 1; i<=n; i++){
                TreeNode* cur = q.front();
                q.pop();
                vec.push_back(cur->val);
                if (cur->left){
                    q.push(cur->left);
                }
                if (cur->right){
                    q.push(cur->right);
                }
            }
            if (leftToRight){
                ans.push_back(vec);
                leftToRight = 0;
            }
            else{
                reverse(vec.begin(), vec.end());
                ans.push_back(vec);
                leftToRight = 1;
            }
        }
        return ans;
    }
};