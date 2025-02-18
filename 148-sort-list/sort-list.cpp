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
    ListNode* sortList(ListNode* head) {
        vector<int> ans;
        ListNode* node=head;
        while(node!=NULL){
            ans.push_back(node->val);
            node=node->next;
        }
        sort(ans.begin(),ans.end());
        ListNode* temp=new ListNode(-1);
        ListNode* curr=temp;
        for(int i=0;i<ans.size();i++){
            curr->next=new ListNode(ans[i]);
            curr=curr->next;
        }
        return temp->next;
    }
};