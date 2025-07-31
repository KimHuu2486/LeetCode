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
    ListNode* MiddleNode(ListNode* head){
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast!=NULL && fast->next!=NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
    ListNode* Reverse(ListNode* head){
        if (head->next == NULL || head == NULL){
            return head;
        }
        ListNode* previous = NULL;
        ListNode* current = head;
        ListNode* next = NULL;
        while (current!=NULL){
            next = current->next;
            current->next = previous;
            previous = current;
            current = next;
        }
        return previous;
    }
    bool isPalindrome(ListNode* head) {
        if (head->next == NULL){
            return true;
        }
        ListNode* reverse = Reverse(MiddleNode(head));
        while (head!=NULL&& reverse!=NULL){
            if (head->val != reverse->val){
                return false;
            }
            head=head->next;
            reverse=reverse->next;
        }
        return true;
    }
};