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
    ListNode* removeElements(ListNode* head, int val) {
        // Handle edge case where list is empty
        if (!head) return head;
        
        // Initialize current and previous pointers
        ListNode* curr = head;
        ListNode* prev = nullptr;

        while (curr) {
            if (curr->val == val) {
                if (curr == head) {
                    // If the node to be removed is the head, move the head to the next node
                    head = head->next;
                    delete curr;    // Delete the current (old head) node
                    curr = head;    // Update curr to the new head
                } else {
                    // For nodes that are not the head, bypass the node and delete it
                    prev->next = curr->next;
                    delete curr;
                    curr = prev->next;  // Move curr to the next node after deletion
                }
            } else {
                // Move both pointers forward if no deletion occurs
                prev = curr;
                curr = curr->next;
            }
        }

        return head;
    }
};
