#include "stdlib.h"

class Solution {
public:
    vector<int> inorderTraversal(TreeNode *root) {
        if (!root) return {};
        TreeNode *current = root;
        vector<TreeNode *> stack;
        vector<int> result;
        while (!stack.empty() || current) {
            if (current) {
                stack.push_back(current);
                current = current->left;
            } else {
                current = stack.back()->right;
                result.push_back(stack.back()->val);
                stack.pop_back();
            }
        }
        return result;
    }


    vector<int> inorderTraversalSecond(TreeNode *root) {
        TreeNode *current = root;
        vector<int> result;
        vector<TreeNode *> stack;
        while (!stack.empty() || current) {
            if (current) {
                stack.push_back(current);
                current = current->left;
            } else {
                result.push_back(stack.back()->val);
                current = stack.back()->right;
                stack.pop_back();
            }
        }
        return result;
    }

    //not correct, the stack should only record nodes that do not need to check left
    vector<int> inorderTraversalThird(TreeNode *root) {
        if (!root) return {};
        vector<int> result;
        vector<TreeNode *> stack = {root};
        TreeNode *temp;
        while(!stack.empty()) {
            temp = stack.back();
            if (temp->left) {
                stack.push_back(temp_left);
            } else {
                result.push_back(temp->val);
                stack.pop_back();
                if (temp->right) stack.push_back(temp->right);
            }
        }
    }
};


int main() {
    TreeNode *root = constructTree("123");
    print(root);
    Solution sol;
    vector<int> result = sol.inorderTraversalSecond(root);
    print(result);
}