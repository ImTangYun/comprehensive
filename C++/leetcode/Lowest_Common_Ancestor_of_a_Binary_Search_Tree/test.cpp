#include <stdio.h>
#include <vector>
#include <stdint.h>

using std::vector;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
void print_vec(vector<TreeNode*> in)
{
    for (uint32_t i = 0; i < in.size(); ++i) {
        printf("%d ", in[i]->val);
    }
    printf("\n");
}

class Solution {
public:

    bool flag;
    void help(TreeNode* root, TreeNode* p, vector<TreeNode*> &tmp) {
        print_vec(tmp);
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

    uint32_t min(uint32_t x, uint32_t y) {
        if (x > y) return y;
        return x;
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
        uint32_t x = min(pv.size(), qv.size());
        for (uint32_t i = 0; i < x; ++i) {
            if (pv[i + 1] != qv[i + 1]) {
                return pv[i];
            }
        }
    }
};


int main()
{
    TreeNode *p = new TreeNode(5);
    p->left = new TreeNode(3);
    p->right = new TreeNode(6);
    p->left->left = new TreeNode(2);
    p->left->right = new TreeNode(4);
    p->left->left->left = new TreeNode(1);
    Solution s;
    s.flag = false;
    vector<TreeNode*> tmp;
    s.help(p, p->left->left, tmp);
    print_vec(tmp);
    return 0;
}
