class Solution {
public:
    bool isBalanced(TreeNode *root) {
        int height;
        return isBalanced(root, height);
    }
private:
    bool isBalancedRecur(TreeNode *root, int &height) {
        if (root == NULL) {
            height = 0;
            return true;
        }
        int left_height;
        int right_height;
        if (!isBalancedRecur(root->left, left_height)) return false;
        if (!isBalancedRecur(root->right, right_height)) return false;
        height = max(left_height, right_height)+1;
        return abs(left_height-right_height) <= 1;
    }
};

class Solution {
public:
    bool isBalanced(TreeNode *root) {
        return isBalancedRecur(root)!=-1;
    }
private:
    int isBalancedRecur(TreeNode *root) {
        if (root == NULL) return 0;
        int left = isBalancedRecur(root->left);
        int right = isBalancedRecur(root->right);
        if (left == -1 || right == -1 || abs(left-right)>1) {
            return -1;
        }
        return max(left, right)+1;
    }
};