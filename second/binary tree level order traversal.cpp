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
    vector<vector<int> > levelOrder(TreeNode *root) {
        vector<TreeNode *> current;
        vector<TreeNode *> next;
        vector<vector<int> > results;
        vector<int> result;
        if (!root) return results;
        current.push_back(root);
        while(!current.empty()) {
            for (int i = 0; i < current.size(); ++i) {
                result.push_back(current[i]->val);
                if (current[i]->left) next.push_back(current[i]->left);
                if (current[i]->right) next.push_back(current[i]->right);
            }
            results.push_back(result);
            current = next;
            next.clear();
            result.clear();
        }
        return results;
    }
};

