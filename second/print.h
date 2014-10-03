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

void print(list<int> l) {
    cout <<"{";
    for (auto it = l.begin(); it != l.end(); ++it) {
        cout <<*it <<" ";
    }
    cout <<"}" <<endl;
}

void print(bool val) {
    if (val) {
        cout <<"true" <<endl;
    } else {
        cout <<"false" <<endl;
    }
}

void print(vector<int> vals) {
    cout <<"{";
    for (int i = 0; i < int(vals.size())-1; ++i) {
        cout <<vals[i] <<" ";
    }
    cout <<vals.back() <<"}" <<endl;
}

void print(vector<vector<int> > vals) {
    cout <<"{\n";
    for (int i = 0; i < vals.size(); ++i) {
        print(vals[i]);
    }
    cout <<"}" <<endl;
}

void print(ListNode *head) {
    cout <<"{";
    while(head && head->next) {
        cout <<head->val <<" ";
        head = head->next;
    }
    cout <<head->val <<"}" <<endl;
}
#endif