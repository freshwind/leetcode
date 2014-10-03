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
        bool left_to_right = true;
        vector<vector<int> > results;
        vector<int> result;
        if (!root) return results;
        vector<TreeNode *> curr = {root};
        vector<TreeNode *> next;
        TreeNode *temp;
        while(!curr.empty()) {
            if (left_to_right) {
                while(!curr.empty()) {
                    temp = curr.back();
                    result.push_back(temp->val);
                    if (temp->left) next.push_back(temp->left);
                    if (temp->right) next.push_back(temp->right);
                    curr.pop_back();
                }
            } else {
                while(!curr.empty()) {
                    temp = curr.back();
                    result.push_back(temp->val);
                    if (temp->right) next.push_back(temp->right);
                    if (temp->left) next.push_back(temp->left);
                    curr.pop_back();
                }
            }
            left_to_right = !left_to_right;
            results.push_back(result);
            result.clear();
            curr = next;
            next.clear();
        }
        return results;
    }
};
