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
    bool isValidBST(TreeNode *root) {
        vector<int> order;
        middleOrder(root, order);
        for (int i = 1; i < order.size(); ++i) {
            if (order[i-1]>=order[i]) {
                return false;
            }
        }
        return true;
    }

    void middleOrder(TreeNode *node, vector<int> &order) {
        if (node != NULL) {
            middleOrder(node->left, order);
            order.push_back(node->val);
            middleOrder(node->right, order);
        }
     }
};


