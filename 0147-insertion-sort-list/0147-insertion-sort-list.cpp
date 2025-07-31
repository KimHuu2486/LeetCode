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
    ListNode* insertionSortList(ListNode* head) {
        if (head->next==NULL){
            return head;
        }
        vector<int> vec;
        ListNode* current = head;
        while (current!=NULL){
            vec.push_back(current->val);
            current = current->next;
        }
        for (int i =1;i<vec.size(); i++){
            int temp = vec[i];
            int j = i-1;
            while (j>=0&&vec[j]>temp){
                vec[j+1] = vec[j];
                j--;
            }
            vec[j+1] = temp;
        }
        current = head;
        for (int i =0; i<vec.size(); i++){
            current->val = vec[i];
            current = current->next;
        }
        return head;
    }
};