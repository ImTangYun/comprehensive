
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
    int maxDepth(TreeNode *root) {
        if (root == NULL) return 0;
        int depth_left = maxDepth(root->left) + 1;
        int depth_right = maxDepth(root->right) + 1;
        return depth_left > depth_right? depth_left:depth_right;
    }
};
