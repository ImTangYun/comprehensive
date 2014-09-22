
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
    vector<int> postorderTraversal(TreeNode *root) {
        vector<int> ret;
        if (root == NULL) return ret;
        stack<TreeNode*> s;
        s.push(root);
        while (!s.empty()) {
            TreeNode* p = s.top();
            if (p->right != NULL) {
                s.push(p->right);
            }
            if (p->left != NULL) {
                s.push(p->left);
            }
            if (p->left == NULL && p->right == NULL) {
                ret.push_back(p->val);
                s.pop();
                while (!s.empty() && (s.top()->left == p || s.top()->right == p)) {
                    p = s.top();
                    ret.push_back(p->val);
                    s.pop();
                }
            }
        }
        return ret;
    }
};
