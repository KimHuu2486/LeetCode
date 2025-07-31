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
 typedef ListNode* node;
 void Reverse(node Left, node Right){
    node previous = NULL;
    node cur= Left;
    node next = NULL;
    while (previous!=Right){
        next = cur->next;
        cur->next = previous;
        previous = cur;
        cur = next;
    }
 }
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (head==NULL || head->next == NULL || left == right){
            return head;
        }
        node Left = head;
        node previous = NULL;
        for (int i = 1; i<left; i++){
            previous = Left;
            Left = Left->next;
        }
        node Right = Left;
        node last = Right->next;
        for (int i = left; i<right; i++){
            Right = last;
            last = last->next;
        }
        if (previous == NULL){
            Reverse(Left,Right);
            Left->next = last;
            return Right;
        }
        Reverse(Left, Right);
        previous->next = Right;
        Left->next = last;       
        return head;
    }
};