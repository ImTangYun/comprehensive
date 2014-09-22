
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
        if (root == NULL) return ret; 
        std::stack<TreeNode*> S;
        TreeNode* p = root;
        do
        {
            while (p != NULL) {
                S.push(p);
                p = p->left;
            }
            if (!S.empty()) {
                p = S.top();
                S.pop();
                ret.push_back(p->val);
                p = p->right;
            }
        }while (p != NULL || !S.empty());
        return ret;
    }
};
