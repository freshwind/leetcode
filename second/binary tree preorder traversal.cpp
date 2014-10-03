#include "stdlib.h"

class Solution {
public:
    vector<int> preorderTraversal(TreeNode *root) {
        if (!root) return {};
        vector<TreeNode *> stack = {root};
        vector<int> result;
        TreeNode *temp;
        while(!stack.empty()) {
            temp = stack.back();
            stack.pop_back();
            result.push_back(temp->val);
            if (temp->right) stack.push_back(temp->right);
            if (temp->left) stack.push_back(temp->left);
        }
        return result;
    }
};

int main() {
    Solution sol;
    TreeNode *root = constructTree("1234");
    print(sol.preorderTraversal(root));
}