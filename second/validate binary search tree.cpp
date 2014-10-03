class Solution {
public:
    bool isValidBST(TreeNode *root) {
        return dfs(root, INT_MIN, INT_MAX);
    }
private:
    bool dfs(TreeNode *root, int min, int max) {
        if (!root) {
            return true;
        }
        if (root->val <= min || root->val >= max) {
            return false;
        }
        return dfs(root->left, min, root->val)&&dfs(root->right, root->val, max);
    }
};

class Solution {
public:
    bool isValidBST(TreeNode *root) {
        if (!root) return true;
        int max, min;
        return valid(root, max, min);
    }
private:
    bool valid(TreeNode *root, int &max, int &min) {
        int left_max, left_min, right_max, right_min;
        if (root->left) {
            if (!valid(root->left, left_max, left_min) || left_max >= root->val) return false;
            min = left_min;
        } else {
            min = root->val;
        }
        if (root->right) {
            if (!valid(root->right, right_max, right_min) || root->val >= right_min) return false;
            max = right_max;
        } else {
            max = root->val;
        }
        return true;
    }
};