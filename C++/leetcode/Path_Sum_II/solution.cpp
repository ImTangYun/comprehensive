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

    void solution(vector<vector<int> >&ret, vector<int>&tmp, int sum, int total, TreeNode* root)
    {
        if (root->left == NULL && root->right == NULL) {
            if (total + root->val == sum) {
                tmp.push_back(root->val);
                ret.push_back(tmp);
                tmp.pop_back();
            }
            return;
        }
        total = total + root->val;
        tmp.push_back(root->val);
        if (root->left != NULL)
            solution(ret, tmp, sum, total, root->left);
        if (root->right != NULL)
            solution(ret, tmp, sum, total, root->right);
        if (root->left || root->right)
            tmp.pop_back();
    }
    vector<vector<int> > pathSum(TreeNode *root, int sum) {
        vector<vector<int> > ret;
        if (root == NULL) return ret;
        vector<int> tmp;
        solution(ret, tmp, sum, 0, root);
        return ret;
    }
};
