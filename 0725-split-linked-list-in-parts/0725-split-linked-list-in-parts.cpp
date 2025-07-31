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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        vector<ListNode*>vec;
        ListNode temp(0);
        temp.next = head;
        int count =0;
        while(head){
            head=head->next;
            count++;
        }
        head = temp.next;
        int num = count/k;
        int residual = count%k;
        if (num == 0){
            for (int i = 1; i<=residual; i++){
                vec.push_back(head);
                ListNode dummy(0);
                dummy.next = head->next;
                head->next = NULL;
                head = dummy.next;
            }
            for (int i =1; i<=k-count%k; i++){
                vec.push_back(NULL);
            }
            return vec;
        }
        for (int i =1; i<=k; i++){
            temp.next = head;
            for (int j = 1; j<num; j++){
                head = head->next;
            }
            if (residual>0){
                head = head->next;
                residual--;
            }
            ListNode dummy(0);
            dummy.next = head->next;
            head->next = NULL;
            head = dummy.next;
            vec.push_back(temp.next);
        }
        return vec;
    }
};