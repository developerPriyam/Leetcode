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
    void reorderList(ListNode* head) {
        //middle of linked list
        ListNode* fast=head;
        ListNode* slow=head;
        while(fast->next&&fast->next->next){
        slow=slow->next;
        fast=fast->next->next;
        }
        //reverse second half
        ListNode* curr=slow->next;
        slow->next=NULL;
        ListNode* prev=NULL;

        while(curr){
            ListNode* node=curr->next;
            curr->next=prev;
            prev=curr;
            curr=node;

        }//merge two half
        ListNode* first=head;
        ListNode* second=prev;
        while(second){
            ListNode* nf=first->next;
            ListNode* nS=second->next;
            first->next=second;
            second->next=nf;
            first=nf;
            second=nS;
        }
    }
};