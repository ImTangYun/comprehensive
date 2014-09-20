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
    vector<int> inorderTraversal(TreeNode *root) {
        vector<int> ret;
        if (!root) return ret;
        stack<pair<TreeNode*, bool> > s;
        s.push(pair<TreeNode*, bool>(root, false));
        bool used;
        TreeNode * p;
        while (!s.empty()) {
            used = s.top().second;
            p = s.top().first;
            s.pop();
            if (used) {
                ret.push_back(p->val);
            } else {
                used = true;
 
                if (p->right) s.push(pair<TreeNode*, bool>(p->right, false));
                s.push(pair<TreeNode*, bool>(p, used));
                if (p->left) s.push(pair<TreeNode*, bool>(p->left, false));
            }
        }
        return ret;
    }
};
