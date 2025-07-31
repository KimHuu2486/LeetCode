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
    ListNode* swapPairs(ListNode* head) {
        if (head==NULL || head->next==NULL){
            return head;
        }
        ListNode* last = head;
        ListNode* next = head->next;
        last->next= next->next;
        next->next= last;
        head = next;
        if (last->next == NULL){
            return head;
        }
        ListNode* previous = last;
        last = last->next;
        next = last->next;
        while (next!=NULL){
            last->next= next->next;
            next->next = last;
            previous->next = next;
            if (last->next==NULL){
                return head;
            }
            previous = last;
            last = last->next;
            next = last->next;
        }
        return head;
    }
};