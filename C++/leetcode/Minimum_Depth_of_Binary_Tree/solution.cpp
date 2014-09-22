
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
    int min_length = 99999999;
    void help(TreeNode* root, int pre_depth)
    {
        if (root->left == NULL && root->right == NULL) {
            int dep = pre_depth + 1;
            min_length = min_length <= dep?min_length:dep;
            return;
        }
        if (root->left != NULL) help(root->left, pre_depth + 1);
        if (root->right != NULL) help(root->right, pre_depth + 1);
    }
    int minDepth(TreeNode *root) {
        if (root == NULL) return 0;
        help(root, 0);
        return min_length;
    }
};
