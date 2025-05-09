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

    ListNode* mergeTwoLinkedList(ListNode* l1, ListNode* l2){
        if(!l1)return l2;
        if(!l2)return l1;

        if(l1->val<=l2->val){
            l1->next=mergeTwoLinkedList(l1->next, l2);
            return l1;
        }else{
            l2->next=mergeTwoLinkedList(l1, l2->next);
            return l2;
        }
    }

    ListNode* Partition_and_Merge(int start,int end,vector<ListNode*>& lists){
        if(start>end) return NULL ;
        if(start==end) return lists[start];
        int mid=start+(end-start)/2;

        ListNode* Lx = Partition_and_Merge(start,mid,lists);
        ListNode* Ly = Partition_and_Merge(mid+1,end,lists);
        return mergeTwoLinkedList(Lx, Ly);
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n=lists.size();
        return Partition_and_Merge(0,n-1,lists);

    }
};