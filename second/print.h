#ifndef PRINT_H
#define PRINT_H
#include <stdlib.h>

void print(TreeNode *head) {
    vector<TreeNode *> current = {head};
    vector<TreeNode *> next;
    cout <<"{\n";
    while (!current.empty()) {
        for (int i = 0; i < current.size(); ++i) {
            if (current[i] == NULL) cout <<"e ";
            else {
                cout <<current[i]->val <<" ";
                next.push_back(current[i]->left);
                next.push_back(current[i]->right);
            }
        }
        cout <<"\n";
        current = next;
        next.clear();
    }
    cout <<"}" <<endl;
}
#endif