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
    ListNode* merge(ListNode* list1, ListNode* list2) {
        if (list1 == nullptr)
            return list2;
        if (list2 == nullptr)
            return list1;

        ListNode* ptr = nullptr;
        if (list1->val <= list2->val) {
            ptr = list1;
            list1 = list1->next;
        } else {
            ptr = list2;
            list2 = list2->next;
        }

        ListNode* curr = ptr;
        while (list1 && list2) {
            if (list1->val <= list2->val) {
                curr->next = list1;
                list1 = list1->next;
            } else {
                curr->next = list2;
                list2 = list2->next;
            }
            curr = curr->next;
        }
        if (list1 != nullptr)
            curr->next = list1;
        if (list2 != nullptr)
            curr->next = list2;
        return ptr;
    }
    ListNode* middle(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
    ListNode* sortList(ListNode* head) {
        if (head == nullptr || head->next == nullptr)
            return head;
        ListNode* mid = middle(head);
        ListNode* lefthead = head;
        ListNode* righthead = mid->next;
        mid->next = nullptr;
        lefthead = sortList(lefthead);
        righthead = sortList(righthead);
        return merge(lefthead, righthead);
    }
};