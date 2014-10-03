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
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        return buildTreeRecur(inorder, 0, inorder.size()-1, postorder, postorder.size()-1);
    }
    TreeNode *buildTreeRecur(vector<int> &inorder, int in_begin, int in_end,
                             vector<int> &postorder, int post_end) {
        if (in_begin == in_end) {
            TreeNode *temp = new TreeNode(inorder[in_begin]);
            return temp;
        } else if (in_begin > in_end) {
            return NULL;
        } else {
            int i = in_begin;
            for (; i <= in_end && inorder[i] != postorder[post_end]; ++i);
            TreeNode *temp = new TreeNode(inorder[i]);
            temp->left = buildTreeRecur(inorder, in_begin, i-1, postorder, post_end-in_end+i-1);
            temp->right = buildTreeRecur(inorder, i+1, in_end, postorder, post_end-1);
            return temp;
        }
    }
};

