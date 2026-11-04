/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        // s1. insert copy nodes in between
        Node* temp = head;
        while (temp != NULL) {
            Node* copyNode = new Node(temp->val);
            copyNode->next = temp->next;
            temp->next = copyNode;
            temp = copyNode->next;
        }

        // s2. connect random pointers
        temp = head;
        while (temp != NULL) {
            Node* copyNode = temp->next;
            if (temp->random) copyNode->random = temp->random->next;
            else copyNode->random = NULL;
            temp = copyNode->next;   // <-- the missing line
        }

        // s3. separate the lists and restore the original
        Node* dNode = new Node(-1);
        Node* res = dNode;
        temp = head;
        while (temp != NULL) {
            res->next = temp->next;
            temp->next = temp->next->next;
            res = res->next;
            temp = temp->next;
        }
        return dNode->next;
    }
};