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
        if (!root) return 0;
        int sum = 0;
        sumNumbersRecur(root, sum, 0);
        return sum;
    }
    void sumNumbersRecur(TreeNode *root, int &sum, int curr) {
        curr = curr*10 + root->val;
        if (!root->left && !root->right) {
            sum += curr;
        } else {
            if (root->left) {
                sumNumbersRecur(root->left, sum, curr);
            }
            if (root->right) {
                sumNumbersRecur(root->right, sum, curr);
            }
        }
    }
};
