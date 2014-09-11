#ifndef CONSTRUCTS_H
#define CONSTRUCTS_H
#include "stdlib.h"

using namespace std;
//construct a tree from a string "1#2"
TreeNode * constructTree(string c) {
    if (c.size() == 0) return NULL;
    if (c[0] == '#') return NULL;
    TreeNode *head = new TreeNode(c[0]-'0');
    vector<TreeNode *> current = {head};
    vector<TreeNode *> next;
    TreeNode *temp;
    int probe = 1;
    while (!current.empty()) {
        for (int i = 0; i < current.size(); ++i) {
            if (probe == c.size()) break;
            if (c[probe] != '#') {
                temp = new TreeNode(c[probe]-'0');
                current[i]->left = temp;
                next.push_back(temp);
            }
            if (++probe == c.size()) break;
            if (c[probe] != '#') {
                temp = new TreeNode(c[probe]-'0');
                current[i]->right = temp;
                next.push_back(temp);
            }
            probe++;
        }
        current = next;
        next.clear();
    }
    return head;
}
#endif