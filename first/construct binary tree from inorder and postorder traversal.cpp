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
        return buildTreeRecur(inorder, postorder, 0, inorder.size()-1,
                              0, postorder.size()-1);
    }
    TreeNode *buildTreeRecur(vector<int> &inorder, vector<int> &postorder,
                         int in_start, int in_end,
                         int post_start, int post_end) {
        if (in_start == in_end) {
            TreeNode *new_node = new TreeNode(inorder[in_start]);
            return new_node;
        }
        if (in_start > in_end) {
            return NULL;
        }
        TreeNode *new_node = new TreeNode(postorder[post_end]);
        //find middle in inorder
        int middle = in_start;
        for (; inorder[middle] != postorder[post_end]; middle++) {

        }
        int left_size = middle - in_start - 1;
        int right_size = in_end - middle - 1;
        new_node->left = buildTreeRecur(inorder, postorder, in_start, middle-1,
                                        post_start, post_start+left_size);
        new_node->right = buildTreeRecur(inorder, postorder, middle+1, in_end,
                          post_start+left_size+1, post_end-1);
        return new_node;
    }
};