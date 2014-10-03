#include "stdlib.h"

class Solution {
public:
    bool isSameTree(TreeNode *p, TreeNode *q) {
        if (p == NULL && q == NULL) return true;
        if (p == NULL || q == NULL || p->val != q->val) return false;
        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
};

int main() {
    Solution sol;
    TreeNode *p = constructTree("123#4");
    TreeNode *q = constructTree("123#45");
    print(sol.isSameTree(p, q));
    print(q);
}
