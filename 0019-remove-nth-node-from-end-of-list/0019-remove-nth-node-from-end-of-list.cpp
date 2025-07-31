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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* temp = head;
        int count = 0;
        while (temp!=NULL){
            count++;
            temp= temp->next;
        }
        if (count == 1){
            return NULL;
        }
        if (count == n){
            return head->next;
        }
        n = count - n;
        temp = head;
        for (int i = 1; i<n; i++){
            temp = temp->next;
        }
        temp->next = temp->next->next;
        return head;
    }
};