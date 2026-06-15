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
    ListNode* deleteMiddle(ListNode* head) {
        // Edge case: single node, delete it, return nullptr
        if (!head || !head->next) return nullptr;
        
        ListNode* slow = head;
        ListNode* fast = head->next->next;
        
        // Move fast by 2, slow by 1
        // When fast reaches end, slow is just before the middle
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        // Delete the middle node
        slow->next = slow->next->next;
        
        return head;
    }
};
