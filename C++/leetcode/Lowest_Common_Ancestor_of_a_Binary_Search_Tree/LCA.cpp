/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:

    bool flag;
    void help(TreeNode* root, TreeNode* p, vector<TreeNode*> &tmp) {
        if (flag) return;
        if (root == NULL) {
            return;
        }
        if (root == p) {
            tmp.push_back(root);
            flag = true;
            return;
        }
        tmp.push_back(root);
        help(root->left, p, tmp);
        help(root->right, p, tmp);
        if (flag) return;
        tmp.pop_back();

    }
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        flag = false;
        vector<TreeNode*> pv;
        vector<TreeNode*> qv;
        help(root, p, pv);
        flag = false;
        help(root, q, qv);

        pv.push_back((TreeNode*)1);
        qv.push_back((TreeNode*)0);
        int x = min(pv.size(), qv.size());
        for (int i = 0; i < x; ++i) {
            if (pv[i + 1] != qv[i + 1]) {
                return pv[i];
            }
        }
    }
};
