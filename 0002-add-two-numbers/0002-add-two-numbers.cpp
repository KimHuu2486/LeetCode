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
 void InsertLast(node &a, int x){
    node temp = new ListNode();
    temp->val = x;
    temp->next = NULL;
    if (a==NULL){
        a =temp;
    }
    else{
        node  p = a;
        while (p->next!=NULL){
            p = p->next;
        }
        p->next = temp;
    }
 }
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* result = NULL;
        int temp = 0;
        int add = 0;
        while(l1!=NULL||l2!=NULL){
            if (l1!=NULL &&l2==NULL){
                add = l1->val + temp;
                l1 = l1->next;
            }
            else if(l1==NULL &&l2!=NULL){
                add = l2->val + temp;
                l2 = l2->next;
            }
            else{
                add = l1->val + l2->val+ temp;
                l1= l1->next;
                l2= l2->next;
            }
            if(add>9){
                InsertLast(result, add%10);
                temp = add/10;
            }
            else{
                InsertLast(result, add);
                temp = 0;
            }

        }
        if (temp!=0){
            InsertLast(result, temp);
        }
        return result;
    }
};