class Solution {
public:
    unordered_map<int, int> idx; // giá trị -> vị trí trong inorder
    
    TreeNode* solve(vector<int>& preorder, vector<int>& inorder,
                    pair<int, int> pre, pair<int, int> in) {
        if (pre.first > pre.second || in.first > in.second)
            return nullptr;

        int rootVal = preorder[pre.first];
        TreeNode* root = new TreeNode(rootVal);

        int mid = idx[rootVal]; // vị trí root trong inorder
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
        for (int i = 0; i < n; i++) {
            idx[inorder[i]] = i; // lưu vị trí trong inorder
        }
        return solve(preorder, inorder, {0, n - 1}, {0, n - 1});
    }
};
