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
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        return build(preorder, 0, inorder, 0, inorder.size()-1);
    }
    TreeNode *build(vector<int> &preorder, int pre_begin,
                    vector<int> &inorder, int in_begin, int in_end) {
        if (in_begin > in_end) {
            return NULL;
        }
        TreeNode *temp = new TreeNode(preorder[pre_begin]);
        int i = in_begin;
        for (; inorder[i] != preorder[pre_begin]; ++i);
        temp->left = build(preorder, pre_begin+1, inorder, in_begin, i-1);
        temp->right = build(preorder, pre_begin+i-in_begin+1, inorder, i+1,in_end);
        return temp;
    }
};
