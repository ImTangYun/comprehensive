/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* removeTheNextNode(ListNode* node) {
        node->next = node->next->next;
        return node;
    }
    ListNode* removeElements(ListNode* head, int val) {
        if (head == NULL) return head;
        ListNode* temp = head; 
        while (temp != NULL && temp->val == val) temp = temp->next;
        head = temp;
        if (head == NULL) return head;
        while (temp->next != NULL) {
            while (temp != NULL && temp->next != NULL &&
            temp->next->val == val) temp = removeTheNextNode(temp);
            if (temp != NULL && temp->next != NULL) temp = temp->next;
        }
        return head;
    }
};