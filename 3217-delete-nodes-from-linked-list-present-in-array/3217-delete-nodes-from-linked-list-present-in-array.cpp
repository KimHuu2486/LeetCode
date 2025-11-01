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
class Solution {
public:
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_set<int>s;
        for (const int& num: nums) {
            s.insert(num);
        }
        while (head && s.count(head->val)){
            head = head->next;
        }
        if (!head) return nullptr;
        ListNode* prev = new ListNode;
        prev->next = head;
        ListNode* cur = head->next;
        while (cur) {
            if (!s.count(cur->val)) {
                prev->next->next = cur;
                prev = prev->next;
            }
            cur = cur->next;
        }
        prev->next->next = cur;
        return head;
    }
};