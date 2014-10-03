class Solution {
public:
    void connect(TreeLinkNode *root) {
        TreeLinkNode *probe = root;
        TreeLinkNode *newProbe = NULL;
        TreeLinkNode *newHead = NULL;
        while (probe != NULL) {
            while (probe!=NULL) {
                if (probe->left != NULL) {
                    newHead = probe->left;
                    if (probe->right != NULL) {
                        newHead->next = probe->right;
                        newProbe = newHead->next;
                    } else {
                        newProbe = newHead;
                    }
                    break;
                }
                if (probe->right != NULL) {
                    newHead = probe->right;
                    newProbe = newHead;
                    break;
                }
                probe = probe->next;
            }
            if (newHead != NULL) {
                probe = probe->next;
                while (probe != NULL) {
                    if (probe->left != NULL) {
                        newProbe->next = probe->left;
                        newProbe = newProbe->next;
                    }
                    if (probe->right != NULL) {
                        newProbe->next = probe->right;
                        newProbe = newProbe->next;
                    }
                    probe = probe->next;
                }
            }
            probe = newHead;
            newProbe = NULL;
            newHead = NULL;
        }
    }
};



