class Solution {
public:
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int, TreeNode*> nodeMap;
        unordered_set<int> children;

        for (const auto& des : descriptions) {
            int parentVal = des[0];
            int childVal = des[1];
            bool isLeft = des[2];

            if (nodeMap.find(parentVal) == nodeMap.end()) {
                nodeMap[parentVal] = new TreeNode(parentVal);
            }
            if (nodeMap.find(childVal) == nodeMap.end()) {
                nodeMap[childVal] = new TreeNode(childVal);
            }

            // Tiến hành nối node con vào node cha
            if (isLeft) {
                nodeMap[parentVal]->left = nodeMap[childVal];
            } else {
                nodeMap[parentVal]->right = nodeMap[childVal];
            }

            children.insert(childVal);
        }

        TreeNode* root = nullptr;
        for (const auto& pair : nodeMap) {
            if (children.find(pair.first) == children.end()) {
                root = pair.second;
                break;
            }
        }

        return root;
    }
};