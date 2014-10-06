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
    ListNode *rotateRight(ListNode *head, int k) {
        ListNode *probe = head;
        int length = 0;
        while (probe != NULL) {
            probe = probe->next;
            length++;
        }
        if (length < 2) return head;
        k = k % length;
        if (k == 0) return head;

        //search for new head
        ListNode *new_head;
        probe = head;
        for (int i = 1; i < length-k; ++i) {
            probe = probe->next;
        }
        new_head = probe->next;
        probe->next = NULL;
        probe = new_head;
        for (int i = 1; i < k; ++i) {
            probe = probe->next;
        }

        probe->next = head;
        return new_head;
    }
};