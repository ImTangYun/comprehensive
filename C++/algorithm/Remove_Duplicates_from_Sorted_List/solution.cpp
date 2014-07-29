
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
    ListNode *deleteDuplicates(ListNode *head) {
        ListNode* p1 = head;
        
        if (p1 == NULL) return NULL;
        ListNode* ret = new ListNode(head->val);
        ListNode* p2;
        ListNode* p3 = ret;
        while (p1->next != NULL) {
            p2 = p1->next;

            while (p2 != NULL && p2->val == p1->val) {
                p2 = p2->next;
            }
            p1->next = p2;
            if (p1->next != NULL) {
                p1 = p1->next;
                p3->next = new ListNode(p1->val);
                p3 = p3->next;
            }
        }
        return ret;
    }
};
