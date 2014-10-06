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
        if (!head || k == 0) return head;
        ListNode *probe = head;
        int length = 1;
        while(probe->next) {
            length++;
            probe = probe->next;
        }
        probe->next = head;
        probe = head;
        for (int i = 1; i < length-k%length; ++i) {
            probe = probe->next;
        }
        ListNode *new_head = probe->next;
        probe->next = NULL;
        return new_head;
    }
};
