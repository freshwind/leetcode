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
    int sumNumbers(TreeNode *root) {
        if (root == NULL) {
            return 0;
        }
        int sum = 0;
        int number = 0;
        sumRecur(root, sum, number);
        return sum;
    }

    void sumRecur(TreeNode *node, int &sum, int number) {
        if (node->left == NULL && node->right == NULL) {
            sum += (number*10 + node->val);
        } else {
            if (node->left != NULL) {
                sumRecur(node->left, sum, number*10 + node->val);
            }
            if (node->right != NULL) {
                sumRecur(node->right, sum, number*10 + node->val);
            }
        }
    }
};