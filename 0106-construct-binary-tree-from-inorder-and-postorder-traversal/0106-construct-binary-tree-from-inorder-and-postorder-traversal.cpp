class Solution {
public:
    unordered_map<int, int> idx; // giá trị -> vị trí trong inorder

    TreeNode* solve(vector<int>& inorder, vector<int>& postorder,
                    pair<int, int> in, pair<int, int> post) {
        if (in.first > in.second || post.first > post.second)
            return nullptr;

        int rootVal = postorder[post.second];
        TreeNode* root = new TreeNode(rootVal);

        int mid = idx[rootVal]; // vị trí root trong inorder
        int leftSize = mid - in.first;

        pair<int, int> leftIn = {in.first, mid - 1};
        pair<int, int> rightIn = {mid + 1, in.second};
        pair<int, int> leftPost = {post.first, post.first + leftSize - 1};
        pair<int, int> rightPost = {post.first + leftSize, post.second - 1};

        root->left = solve(inorder, postorder, leftIn, leftPost);
        root->right = solve(inorder, postorder, rightIn, rightPost);

        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = inorder.size();
        for (int i = 0; i < n; i++) {
            idx[inorder[i]] = i; // lưu vị trí inorder
        }
        return solve(inorder, postorder, {0, n - 1}, {0, n - 1});
    }
};
