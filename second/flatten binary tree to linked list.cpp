class Solution {
public:
    void flatten(TreeNode *root) {
        TreeNode *probe = root;
        TreeNode *right_most;
        while(probe) {
            if (probe->left) {
                right_most = probe->left;
                while(right_most->right != NULL) {
                    right_most = right_most->right;
                }
                right_most->right = probe->right;
                probe->right = probe->left;
                probe->left = NULL;
            }
            probe = probe->right;
        }
    }
};