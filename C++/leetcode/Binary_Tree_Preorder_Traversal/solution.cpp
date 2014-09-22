
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
    vector<int> preorderTraversal(TreeNode *root) {
        TreeNode* p = root;
        vector<int> ret;
        if (p == NULL) return ret;
        std::stack<TreeNode*> S;
        while (p != NULL) {
            ret.push_back(p->val);
            if (p->right != NULL) S.push(p->right);
            if (p->left != NULL) S.push(p->left);

            if (!S.empty()) {
                p = S.top();
                S.pop();
            } else p = NULL;
        }
        return ret;
    }
};
