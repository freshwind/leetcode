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
    vector<vector<int> > levelOrderBottom(TreeNode *root) {
        vector<vector<int> > results;
        if (root == NULL) return results;
        vector<int> result;
        vector<TreeNode *> current = {root};
        vector<TreeNode *> next;
        while (!current.empty()) {
            for (int i = 0; i < current.size(); ++i) {
                result.push_back(current[i]->val);
                if (current[i]->left) next.push_back(current[i]->left);
                if (current[i]->right) next.push_back(current[i]->right);
            }
            results.push_back(result);
            current = next;
            result.clear();
            next.clear();
        }
        reverse(results.begin(), results.end());
        return results;
    }
};