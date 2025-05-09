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
    bool hasCycle(ListNode *head) {
        if(head==NULL){
            return false;
        }
        if(head->next == NULL){
            return false;
        }
        if(head->next->next == NULL){
            return false;
        }
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast->next!=NULL && slow->next!=NULL ){
            fast=fast->next;
            if(fast->next!=NULL)fast=fast->next;
            slow=slow->next;

            if(slow==fast)return true;
        }
    return false;
    }
};