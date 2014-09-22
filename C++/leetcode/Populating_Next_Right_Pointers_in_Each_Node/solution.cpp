
/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        if (root == NULL) return;
        if (root->left == NULL || root->right == NULL) return;
        TreeLinkNode* p = root;
        while (p->left != NULL) {
            TreeLinkNode* p1 = p;
            while (p1 != NULL) {
                if (p1->next != NULL) {
                    p1->left->next = p1->right;
                    p1->right->next = p1->next->left;
                } else {
                    p1->left->next = p1->right;
                    p1->right->next = NULL;
                }
                p1 = p1->next;
            }
            p = p->left;
        }
    }
};
