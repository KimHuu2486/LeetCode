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
    ListNode* removeElements(ListNode* head, int val) {
        while (head && head->val==val){
            head = head->next;
        }
        if (!head){
            return head;
        }
        ListNode* cur = head->next;
        ListNode* prev = head; 
        while(cur){
            while(cur && cur->val==val){
                cur = cur->next;
            }
            prev->next = cur;
            if (!cur) break;
            prev = cur;
            cur = cur->next;
        }
        return head;
    }
};