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
    int pairSum(ListNode* head) {
        stack<int> st;
        ListNode* slow = head;
        ListNode* fast = head;
        
        // Find middle using slow/fast pointers
        while (fast && fast->next) {
            st.push(slow->val);
            slow = slow->next;
            fast = fast->next->next;
        }
        
        // Now slow is at second half, stack has first half (reversed)
        int maxSum = 0;
        while (slow) {
            maxSum = max(maxSum, slow->val + st.top());
            st.pop();
            slow = slow->next;
        }
        
        return maxSum;
    }
};
