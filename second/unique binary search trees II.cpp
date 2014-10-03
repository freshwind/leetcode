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
    vector<TreeNode *> generateTrees(int n) {
        return generateTreesRecur(1, n);
    }
private:
    vector<TreeNode *> generateTreesRecur(int small, int large) {
        vector<TreeNode *> result;
        if (small == large) {
            TreeNode *head = new TreeNode(small);
            result.push_back(head);
        } else if (small > large) {
            result.push_back(NULL);
        } else {
            vector<TreeNode *> left;
            vector<TreeNode *> right;
            TreeNode *head;
            for (int i = small; i <= large; ++i) {
                left = generateTreesRecur(small, i-1);
                right = generateTreesRecur(i+1, large);
                for (int l = 0; l < left.size(); ++l) {
                for (int r = 0; r < right.size(); ++r) {
                    head = new TreeNode(i);
                    head->left = left[l];
                    head->right = right[r];
                    result.push_back(head);
                }
                }
            }
        }
        return result;
    }
};
