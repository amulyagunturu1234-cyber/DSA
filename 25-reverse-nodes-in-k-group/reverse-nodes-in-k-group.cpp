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
    ListNode* reverseList(ListNode* head) {
        ListNode* temp = head;
        ListNode* prev = NULL;
        ListNode* front = NULL;
        while(temp != NULL){
            front = temp->next;
            temp->next = prev;
            prev = temp;
            temp = front;
        }
        return prev;
    }

    ListNode* findKthNode(ListNode* temp, int k){
        while(temp != NULL){
            k--;
            if(k == 0) return temp;
            temp = temp->next;
        }
        return NULL;
    }

public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp = head;
        ListNode* prevNode = NULL;
        ListNode* nextNode;

        while(temp != NULL){
            ListNode* kthNode = findKthNode(temp, k);
            if(kthNode == NULL){
                if(prevNode) prevNode->next = temp;
                break;
            }
            nextNode = kthNode->next;
            kthNode->next = NULL;       // cut the group
            reverseList(temp);          // reverse it
            if(temp == head) head = kthNode;
            else prevNode->next = kthNode;
            prevNode = temp;            // temp is now the tail
            temp = nextNode;
        }
        return head;
    }
};