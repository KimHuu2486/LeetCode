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
 typedef struct ListNode* node;
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (head==NULL||head->next==NULL||k==0){
            return head;
        }
        node end = head;
        int count = 1;
        while (end->next!=NULL){
            end = end->next;
            count++;
        }
        k = k%count;
        k = count - k;
        for (int i = 1; i<=k; i++){
            node temp = head->next;
            end->next = head;
            end = head;
            end->next = NULL;
            head = temp;
        }
        return head;
    }
};