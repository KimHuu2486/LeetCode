/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    int SizeList(ListNode* head){
        ListNode* temp = head;
        int count= 0;
        while (head!=NULL){
            count++;
            head= head->next;
        }
        return count;
    }
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int len1 = SizeList(headA);
        int len2 = SizeList(headB);
        while (len1>len2){
            len1--;
            headA= headA->next;
        }
        while (len2>len1){
            len2--;
            headB = headB->next;
        }
        while (headA!=headB){
            headA = headA->next;
            headB = headB->next;
        }
        return headA;
    }
};