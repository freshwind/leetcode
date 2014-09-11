#include "stdlib.h"

class Solution {
public:
    int maxDepth(TreeNode *root) {
        if (root == NULL) return 0;
        int son_height = max(maxDepth(root->left),maxDepth(root->right));
        return son_height+1;
    }
};

int main() {
    Solution sol;
    TreeNode *root = constructTree("123#4");
    print(root);
    return 1;
}