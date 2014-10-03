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
    vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
        vector<TreeNode *> current_level;
        vector<TreeNode *> next_level;
        current_level.push_back(root);
        vector<vector<int> > results;
        vector<int> result;
        if (root == NULL)  return results;
        TreeNode *temp_node;
        int level = 1;
        while (!current_level.empty()) {
            while (!current_level.empty()) {
                temp_node = current_level.back();
                result.push_back(temp_node->val);
                if (level%2 == 1) {
                    if (temp_node->left != NULL) next_level.push_back(temp_node->left);
                    if (temp_node->right != NULL) next_level.push_back(temp_node->right);
                } else {
                    if (temp_node->right != NULL) next_level.push_back(temp_node->right);
                    if (temp_node->left != NULL) next_level.push_back(temp_node->left);
                }
                current_level.pop_back();
            }
            results.push_back(result);
            result.clear();
            current_level = next_level;
            next_level.clear();
            ++level;
        }
        return results;
    }
};