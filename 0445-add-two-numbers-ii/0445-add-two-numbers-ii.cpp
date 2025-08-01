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
    int Size(ListNode* head){
        int count = 0;
        while ( head!=NULL){
            count++;
            head=head->next;
        }
        return count;
    }
    ListNode* MakeNode(int x){
        ListNode* temp = new ListNode;
        temp->val = x;
        temp->next = NULL;
        return temp;
    }
    void Reverse(ListNode* &head){
        ListNode temp(0);
        temp.next = head;
        ListNode* prev = &temp;
        ListNode* cur = head;
        ListNode* next = cur->next;
        while(next!=NULL){
            cur->next = next->next;
            next->next = prev->next;
            prev->next = next;
            next = cur->next;
        }
        head = prev->next;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        Reverse(l1);
        Reverse(l2);
        ListNode temp(0);
        if (Size(l1)<Size(l2)){
            temp.next = l1;
            l1 = l2;
            l2 = temp.next;
        }   
        temp.next = l1;
        while(l2!=NULL){
            l1->val+=l2->val;
            if (l1->val>9){
                if (!l1->next){
                    l1->val -=10;
                    l1->next = MakeNode(1); 
                    l1 = l1->next;
                    break;
                }
                l1->next->val++;
                l1->val-=10;
            }
            l1 = l1->next;
            l2 = l2->next;
        }
        while(l1!=NULL && l1->val>9){
            if (!l1->next){
                l1->val -=10;
                l1->next = MakeNode(1); 
                l1 = l1->next;
                break;
            }
            l1->val -=10;
            l1->next->val++;
            l1 = l1->next;
        }
        l1 = temp.next;
        Reverse(l1);
        return l1;
    }
};