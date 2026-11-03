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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* temp=head;
        int len=0;
        while(temp!=NULL){
            len++;
            temp=temp->next;
        }
        if(len==n){
            ListNode* newHead=head->next;
            delete(head);
            return newHead;
        }
        temp=head;
        int rem=len-n;
        while(temp!=NULL){
            rem--;
            if(rem==0) break;
            temp=temp->next;
        }
        ListNode* delNode=temp->next;
        temp->next=temp->next->next;
        delete delNode;
        return head;
    }
};