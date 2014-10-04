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
    void help(TreeNode**root, vector<int> &inorder, int f1, int e1,
        vector<int>& postorder, int f2, int e2)
    {
        if (e1 < f1) return;
        if (e1 == f1) {
            *root = new TreeNode(inorder[f1]);
            return;
        }
        int tmp = postorder[e2];
        int i = 0;
        for (; f1 + i <= e1; ++i) {
            if (inorder[f1 +i] == tmp) break;
        }
        *root = new TreeNode(tmp);
        help(&((*root)->left), inorder, f1, f1 + i - 1, postorder, f2, f2 + i - 1);
        help(&((*root)->right), inorder, f1 + i + 1, e1, postorder, f2 + i, e2 - 1);
    }
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        if (inorder.size() <= 0) return NULL;
        TreeNode* ret;
        help(&ret, inorder, 0, inorder.size() - 1, postorder, 0, postorder.size() - 1);
        return ret;
    }
};
