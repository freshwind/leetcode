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
    int minDepth(TreeNode *root) {
        if (root == NULL) return 0;
        int minDepth = 100000;
        minDepthRecur(minDepth, 1, root);
        return minDepth;
    }

    void minDepthRecur(int &minDepth, int depth, TreeNode *node) {
        if (depth >= minDepth) {
            return;
        }
        if (node->left == NULL && node->right == NULL) {
            minDepth = depth;
            return;
        }
        if (node->left != NULL) {
            minDepthRecur(minDepth, depth+1, node->left);
        }
        if (node->right != NULL) {
            minDepthRecur(minDepth, depth+1, node->right);
        }
    }
};