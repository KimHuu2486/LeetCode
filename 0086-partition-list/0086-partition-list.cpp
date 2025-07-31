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
    ListNode* partition(ListNode* head, int x) {
        ListNode temp(0);
        ListNode res(0);
        ListNode* less = NULL;
        ListNode* great = NULL;
        while(head!=NULL){
            if (head->val < x){
                if (less==NULL){
                    less = head;
                    temp.next = less;
                }
                else{
                    less->next = head;
                    less = less->next;
                }
            }
            else{
                if(great == NULL){
                    great = head;
                    res.next = great;
                }
                else{
                    great->next = head;
                    great = great->next;
                }
            }
            head=head->next;
        }
        if (less==NULL){
            return res.next;
        }
        if (great == NULL){
            return temp.next;
        }
        great->next = NULL;
        less->next = res.next;
        return temp.next;
    }
};