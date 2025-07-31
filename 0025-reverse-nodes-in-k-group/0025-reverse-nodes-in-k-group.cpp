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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (k==1){
            return head;
        }
        ListNode temp(0);
        temp.next = head;
        ListNode* previous = &temp;
        ListNode* current = head;
        int count = 0;
        while (current){
            count++;
            current= current->next;
        }
        while(count>=k){
            current = previous->next;
            ListNode* next = current->next;
            for (int i = 1; i<k ;i++){
                current->next = next->next;
                next->next = previous->next;
                previous->next = next;
                next = current->next;
            }
            count-=k;
            previous = current;
        }
        return temp.next;
    }
};