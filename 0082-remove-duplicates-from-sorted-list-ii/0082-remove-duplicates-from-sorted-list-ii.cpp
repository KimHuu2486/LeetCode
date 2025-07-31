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
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == NULL || head->next==NULL){
            return head;
        }
        ListNode* temp = head;
        map<int, int>value;
        while (temp!=NULL){
            int count = 1;
            while (temp->next!=NULL && temp->val == temp->next->val){
                count++;
                temp = temp->next;
            }
            value[temp->val] = count;
            temp = temp->next;
        }
        vector<int>vec;
        for (auto it: value){
            if (it.second==1){
                vec.push_back(it.first);
            }
        }
        if (vec.size()==0){
            return NULL;
        }
        temp =head;
        ListNode* previous = NULL;
        for (int i = 0; i<vec.size(); i++){
            temp->val = vec[i];
            previous = temp;
            temp = temp->next;
        }
        previous->next = NULL;
        return head;
    }
};