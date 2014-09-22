
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
    bool hasCycle(ListNode *head) {
        ListNode* p1 = head;
        ListNode* p2 = head;
        if (p1 == NULL) return false;
        if (p2->next == NULL) return false;
        while (true) {
            p2 = p2->next;
            if (p2 == NULL) return false;
            if (p2 == p1) return true;
            p2 = p2->next;
            if (p2 == NULL) return false;
            if (p2 == p1) return true;
            p1 = p1->next;
        }
    }
};
