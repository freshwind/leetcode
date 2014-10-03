// class Solution {
// public:
//     int minDepth(TreeNode *root) {
//         if (!root) return 0;
//         vector<TreeNode *> current = {root};
//         vector<TreeNode *> next;
//         int depth = 1;
//         while(1) {
//             for (int i = 0; i < current.size(); i++) {
//                 if (!current[i]->left && !current[i]->right) {
//                     return depth;
//                 }
//                 if (current[i]->left) next.push_back(current[i]->left);
//                 if (current[i]->right) next.push_back(current[i]->right);
//             }
//             current = next;
//             next.clear();
//             depth++;
//         }
//     }
// };
#include "stdlib.h"

class Solution {
public:
    int minDepth(TreeNode *root) {
        if (!root) return 0;
        queue<TreeNode *> q;
        q.push(root);
        int curr = 1;
        int next = 0;
        int lvl = 1;
        while (1) {
            curr--;
            if (!q.front()->left && !q.front()->right) return lvl;
            if (q.front()->left) q.push(q.front()->left);
            if (q.front()->right) q.push(q.front()->right);
            q.pop();
            if (!curr) {
                curr = next;
                next = 0;
                lvl++;
            }
        }
    }
};

int main() {
    Solution sol;
    return 1;
}