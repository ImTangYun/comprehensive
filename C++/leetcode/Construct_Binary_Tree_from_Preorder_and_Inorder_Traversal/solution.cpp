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
    void help(TreeNode** root, vector<int> &preorder, int f1, int e1,
        vector<int>&inorder, int f2, int e2)
    {
        if (f1 > e1) return;
        if (f1 == e1) {
            *root = new TreeNode(preorder[f1]);
            return;
        }
        int index = 0;
        int tmp = preorder[f1];
        for (; index + f2 <= e2; ++index) {
            if (inorder[index + f2] == tmp) break;
        }
        *root = new TreeNode(tmp);
        help(&((*root)->left), preorder, f1 + 1, f1 + index, inorder, f2, f2 + index - 1);
        help(&((*root)->right), preorder, f1 + index + 1, e1, inorder, f2 + index + 1, e2);
    }
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        if (preorder.size() <= 0) return NULL;
        TreeNode* root;
        help(&root, preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1);
        return root;
    }
};
