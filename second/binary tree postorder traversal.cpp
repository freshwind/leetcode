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
    vector<int> postorderTraversal(TreeNode *root) {
        if (!root) return {};
        vector<int> result;
        vector<TreeNode *> stack = {root};
        TreeNode *temp;
        while (!stack.empty()) {
            temp = stack.back();
            stack.pop_back();
            result.push_back(temp->val);
            if (temp->left) {
                stack.push_back(temp->left);
            }
            if (temp->right) {
                stack.push_back(temp->right);
            }
        }
        reverse(result.begin(), result.end());
        return result;
    }
};

