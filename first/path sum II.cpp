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
    vector<vector<int> > pathSum(TreeNode *root, int sum) {
        vector<vector<int> > results;
        if (root == NULL) {
            return results;
        }
        vector<int> curr;
        curr.push_back(root->val);
        pathSumRecur(root, sum-root->val, results, curr);
        return results;
    }

    void pathSumRecur(TreeNode *r, int sum, vector<vector<int> >& res, vector<int>& curr) {
        if (r->left == NULL && r->right == NULL && sum == 0) {
            res.push_back(curr);
        } else {
            if (r->left != NULL) {
                curr.push_back(r->left->val);
                pathSumRecur(r->left, sum - r->left->val, res, curr);
                curr.pop_back();
            }
            if (r->right != NULL) {
                curr.push_back(r->right->val);
                pathSumRecur(r->right, sum - r->right->val, res, curr);
                curr.pop_back();
            }
        }
    }
};

