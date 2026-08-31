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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        
        vector<int> ans = {-1, -1};

        if (head == NULL || head->next == NULL || head->next->next == NULL)
            return ans;

        ListNode* prev = head;
        ListNode* curr = head->next;

        int pos = 1;

        int first = -1;
        int last = -1;
        int minDist = INT_MAX;

        while (curr->next != NULL) {

            int nextVal = curr->next->val;

            // Check if curr is a critical point
            if ((curr->val > prev->val && curr->val > nextVal) ||
                (curr->val < prev->val && curr->val < nextVal)) {

                // First critical point
                if (first == -1) {
                    first = pos;
                }
                else {
                    // Distance from previous critical point
                    minDist = min(minDist, pos - last);
                }

                last = pos;
            }

            prev = curr;
            curr = curr->next;
            pos++;
        }

        // Fewer than 2 critical points
        if (first == -1 || first == last)
            return ans;

        ans[0] = minDist;
        ans[1] = last - first;

        return ans;
    }
};