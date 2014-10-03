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

    vector<TreeNode *> generateTreesRecur(int small, int large) {
        vector<TreeNode *> result;
        if(small>large) {
            result.push_back(NULL);
            return result;
        }
        if(small==large) {
            TreeNode *temp_node = new TreeNode(small);
            result.push_back(temp_node);
            return result;
        }
        for(int i = small; i <= large; ++i) {
            vector<TreeNode *> left_children_result = generateTreesRecur(small, i-1);
            vector<TreeNode *> right_children_result = generateTreesRecur(i+1, large);
            for(int m = 0; m != left_children_result.size(); ++m) {
                for(int n = 0; n != right_children_result.size(); ++n) {
                    TreeNode *temp_node = new TreeNode(i);
                    temp_node->left = left_children_result[m];
                    temp_node->right = right_children_result[n];
                    result.push_back(temp_node);
                }
            }

        }
        return result;
    }
};