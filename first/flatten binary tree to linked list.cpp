class Solution {
public:
    void flatten(TreeNode *root) {
        TreeNode *probe = root;
        TreeNode *tempRight;
        TreeNode *mostRight;
        while (probe) {
            if (probe->left) {
                tempRight = probe->right;
                probe->right = probe->left;
                mostRight = probe->left;
                while (mostRight->right != NULL) {
                    mostRight = mostRight->right;
                }
                mostRight->right = tempRight;
                probe->left = NULL;
            }
            probe = probe->right;
        }
    }
};