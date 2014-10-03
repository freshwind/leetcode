#include "stdlib.h"

class Solution {
public:
    //time 100ms
    void connect_my_solution(TreeLinkNode *root) {
        TreeLinkNode *head = root;
        TreeLinkNode *probe;
        TreeLinkNode *ref = new TreeLinkNode(-1);
        TreeLinkNode *son;
        while (head != NULL && head->left != NULL) {
            probe = head;
            son = ref;
            while (probe != NULL) {
                son->next = probe->left;
                son = son->next;
                son->next = probe->right;
                son = son->next;
                probe = probe->next;
            }
            head = head->left;
        }
        delete ref;
    }

    //time 145ms notonly's solution
    void connect_notonly(TreeLinkNode *root) {
        if (root && root->left) {
            root->left->next = root->right;
            if (root->next) {
                root->right->next = root->next->left;
            }
            connect_notonly(root->left);
            connect_notonly(root->right);
        }
    }

    //teim 76 ms senhong's solution
    void connect(TreeLinkNode *root) {
        TreeLinkNode *head = root;
        TreeLinkNode *probe;
        while (head && head->left) {
            probe = head;
            while (probe) {
                probe->left->next = probe->right;
                probe->right->next = probe->next ? probe->next->left:NULL;
                probe = probe->next;
            }
            head = head->left;
        }
    }
};