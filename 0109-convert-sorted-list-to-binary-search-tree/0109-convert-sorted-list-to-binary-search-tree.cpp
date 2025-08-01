/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    void dfs(TreeNode*& root, ListNode*& head){
        if (!root) return;
        dfs(root->left, head);
        root->val = head->val;
        head = head->next;
        dfs(root->right, head);

    }
    TreeNode* sortedListToBST(ListNode* head) {
        if (!head) return NULL;
        int n = 0;
        ListNode* temp = head;
        while (temp){
            n++;
            temp = temp->next;
        }
        queue<TreeNode*>q;
        TreeNode* root = new TreeNode();
        q.push(root);
        n--;
        while (n>0){
            int size = q.size();
            for (int i = 0; i<size; i++){
                TreeNode* res = q.front();
                q.pop();
                if (n>0){
                    res->left = new TreeNode;
                    n--;
                    q.push(res->left);
                }
                if (n>0){
                    res->right = new TreeNode;
                    n--;
                    q.push(res->right);
                }
            }
        }
        dfs(root, head);
        return root;
    }
};