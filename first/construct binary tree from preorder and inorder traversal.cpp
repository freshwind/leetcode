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
        return buildTreeRecur2(preorder, inorder,
                    0, inorder.size()-1, 0, preorder.size()-1);
    }
    TreeNode *buildTreeRecur2(vector<int> &preorder, vector<int> &inorder,
                              int pre_start, int pre_end,
                              int in_start, int in_end) {
        if (in_start > in_end) return NULL;
        if (in_start == in_end) {
            TreeNode *new_node = new TreeNode(inorder[in_start]);
            return new_node;
        }
        int middle = in_start;
        for (; inorder[middle] != preorder[pre_start]; ++middle) {

        }
        TreeNode *new_node = new TreeNode(inorder[middle]);
        int left_size = middle - 1 - in_start;
        new_node->left = buildTreeRecur2(preorder, inorder,
                                         pre_start+1, pre_start+left_size+1,
                                         in_start, middle-1);
        new_node->right = buildTreeRecur2(preorder, inorder,
                                          pre_start+left_size+2, pre_end,
                                          middle+1, in_end);
        return new_node;
    }
};