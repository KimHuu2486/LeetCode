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
    TreeNode* solve(vector<int>& inorder, vector<int>& postorder, pair<int,int>in, pair<int,int>post){
        if (in.second<in.first) return nullptr;
        TreeNode* root = new TreeNode;
        root->val = postorder[post.second];
        if (in.first == in.second){
            root->left =NULL;
            root->right = NULL;
            return root;
        }
        int mid;
        for (int i = in.first; i<=in.second; i++){
            if (inorder[i] == root->val) {
                mid = i;
                break;
            }
        }
        int leftSize = mid - in.first;
        pair<int,int>leftIn = {in.first, mid - 1};
        pair<int,int>rightIn = {mid + 1, in.second};
        pair<int, int>leftPost = {post.first, post.first + leftSize -1};
        pair<int, int>rightPost = {post.first + leftSize, post.second - 1};
        root->left= solve(inorder, postorder, leftIn, leftPost);
        root->right = solve(inorder, postorder, rightIn, rightPost);
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = inorder.size();
        return solve(inorder, postorder, {0, n-1}, {0, n-1});
    }
};