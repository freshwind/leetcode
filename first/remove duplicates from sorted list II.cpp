/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *deleteDuplicates(ListNode *head) {
        if (head == NULL) return head;
        ListNode *fake_head = new ListNode(-1);
        fake_head->next = head;
        ListNode *anchor = fake_head;
        ListNode *probe = head->next;
        ListNode *temp;
        bool to_delete = false;
        while (probe != NULL) {
            if (anchor->next->val != probe->val) {
                if (to_delete) {
                    temp = anchor->next;
                    anchor->next = probe;
                    probe = probe->next;
                    delete temp;
                    to_delete = false;
                } else {
                    anchor = anchor->next;
                    probe = probe->next;
                }
            } else {
                to_delete = true;
                temp = probe;
                probe = probe->next;
                delete temp;
            }
        }
        if (to_delete) {
            temp = anchor->next;
            anchor->next = NULL;
            delete temp;
        }
        return fake_head->next;
    }
};