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
    ListNode* reverse(ListNode* head){
        ListNode* prev = nullptr;
        ListNode* temp = head;
        while(temp){
            ListNode* next = temp->next;
            temp->next = prev;
            prev = temp;
            temp = next;
        } 
        return prev;

    }
public:
    ListNode* removeNodes(ListNode* head) {
        if(!head && !head -> next) return head;
        head = reverse(head);
        ListNode* max = head;
        ListNode* temp = head->next;
        
        while(temp){
            if(max-> val > temp-> val) {
                ListNode* removalNode = temp;
                temp = temp->next;
                delete removalNode;
                max-> next = temp;
            }
            else {
                max = temp;
                temp = temp -> next;
            }

        }

        return reverse(head);

    }
};