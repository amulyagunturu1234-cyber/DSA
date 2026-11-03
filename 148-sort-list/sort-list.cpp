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
    private:
    ListNode* ms(ListNode* head){
        if(head==NULL || head->next==NULL) return head;
        ListNode* middle=findmiddle(head);
        ListNode* leftHead=head;
        ListNode* rightHead=middle->next;
        middle->next=NULL;
        leftHead=ms(leftHead); 
        rightHead=ms(rightHead);
        return mergeTwoLists(leftHead,rightHead);
    }
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* dummyNode=new ListNode(-1);
        ListNode* curr=dummyNode;
        ListNode* t1=list1;
        ListNode* t2=list2;
        while(t1!=NULL && t2!=NULL){
            if(t1->val<t2->val){
                curr->next=t1;
                curr=curr->next;
                t1=t1->next;
            }
            else{
                curr->next=t2;
                curr=curr->next;
                t2=t2->next;
            }
        }
        if(t1) curr->next=t1;
        if(t2) curr->next=t2;
        return dummyNode->next;
    }
    ListNode* findmiddle(ListNode* head){
        ListNode* fast=head->next;
        ListNode* slow=head;
        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow;
    }
public:
    ListNode* sortList(ListNode* head) {
        return ms(head);
    }
};