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
    ListNode* reverse(ListNode*&slow){
        ListNode temp(0);
        temp.next = slow;
        ListNode* cur = slow;
        ListNode* prev = &temp;
        ListNode* next = cur->next;
        while(next!=NULL){
            cur->next = next->next;
            next->next = prev->next;
            prev->next = next;
            next = cur->next;
        }
        return prev->next;
    }
    void reorderList(ListNode* head) {
        if (head->next== NULL || head->next->next == NULL) return ;
        ListNode res(0);
        res.next = head;
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* prev = NULL;
        while(fast!=NULL && fast->next!=NULL){
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        prev->next = NULL;
        slow = reverse(slow);
        ListNode* temp =NULL;
        while(head->next!=NULL){
            temp = slow->next;
            slow->next = head->next;
            head->next = slow;
            head = slow->next;
            slow = temp;
        }
        head->next = slow;
        head = res.next;
    }
};