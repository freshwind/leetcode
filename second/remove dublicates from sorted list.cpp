#include "stdlib.h"

class Solution {
public:
    ListNode *deleteDuplicates(ListNode *head) {
        if (head == NULL) return NULL;
        ListNode *current = head;
        ListNode *probe = current->next;
        while (probe) {
            if (probe->val == current->val) {
                current->next = probe->next;
                delete probe;
            } else {
                current = probe;
            }
            probe = current->next;
        }
        return head;
    }
};

int main() {

}