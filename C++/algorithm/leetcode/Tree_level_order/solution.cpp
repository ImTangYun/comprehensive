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
    vector<vector<int> > levelOrder(TreeNode *root) {
        queue<TreeNode*> q1;
        queue<TreeNode*> q2;
        vector<vector<int> > ret;
        bool flag = false;
        q1.push(root);
        while (!q1.empty() || !q2.empty()) {
            vector<int> tmp;
            if (!flag) {
                while (!q1.empty()) {
                    TreeNode* p = q1.front();
                    q1.pop();
                    if (p != NULL) {
                        tmp.push_back(p->val);
                        q2.push(p->left);
                        q2.push(p->right);
                    }
                }
            } else {
                while (!q2.empty()) {
                    TreeNode* p = q2.front();
                    q2.pop();
                    if (p != NULL) {
                        tmp.push_back(p->val);
                        q1.push(p->left);
                        q1.push(p->right);
                    }
                }
            }
            if (tmp.size() > 0)
                ret.push_back(tmp);            
            flag = !flag;
        }
        return ret;
    }
};
