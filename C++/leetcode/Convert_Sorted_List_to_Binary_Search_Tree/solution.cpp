/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void split(ListNode* head, ListNode**left, ListNode**right, ListNode**node)
    {
        if (head == NULL) {
            *node = NULL;
            *left = NULL;
            *right = NULL;
            return;
        }
        if (head->next == NULL) {
            *node = head;
            *left = NULL;
            *right = NULL;
            return; 
        }
        int count = 0;
        *node = head;
        while (*node != NULL) {
            *node = (*node)->next;
            ++count;
        }
        if (count == 2) {
            *left = NULL;
            *node = head;
            *right = (*node)->next;
            (*node)->next = NULL;
            return;
        }
        int middle = count / 2;
        *node = head;
        *left = head;
        for (int i = 0; i < middle - 1; ++i) {
            *node = (*node)->next;
        }
        ListNode* p = *node;
        *node = (*node)->next;
        *right = (*node)->next;
        (*node)->next = NULL;
        p->next = NULL;
    }
    TreeNode *sortedListToBST(ListNode *head) {
        if (head == NULL) return NULL;
        ListNode* left;
        ListNode* right;
        ListNode* node;
        split(head, &left, &right, &node);
        if (node == NULL) return NULL;
        TreeNode* root = new TreeNode(node->val);
        root->left = sortedListToBST(left);
        root->right = sortedListToBST(right);
        return root;
    }
};
