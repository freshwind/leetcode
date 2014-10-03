class Solution {
public:
    void connect(TreeLinkNode *root) {
        TreeLinkNode *probe;
        TreeLinkNode *current;
        TreeLinkNode *fake_head = new TreeLinkNode(-1);
        fake_head->next = root;
        while (fake_head->next) {
            probe = fake_head->next;
            fake_head->next = NULL;
            current = fake_head;
            while(probe) {
                if (probe->left) {
                    current->next = probe->left;
                    current = current->next;
                }
                if (probe->right) {
                    current->next = probe->right;
                    current = current->next;
                }
                probe = probe->next;
            }
        }
        delete fake_head;
    }
};
