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
    ListNode *partition(ListNode *head, int x) {
        if (head == NULL) {
            return NULL;
        }
        ListNode *small_head = new ListNode(0);
        ListNode *large_head = new ListNode(0);
        ListNode *small_probe = small_head;
        ListNode *large_probe = large_head;
        ListNode *probe = head;
        while (probe != NULL) {
            if (probe->val < x) {
                small_probe->next = probe;
                small_probe = small_probe->next;
            } else {
                large_probe->next = probe;
                large_probe = large_probe->next;
            }
            probe = probe->next;
        }
        small_probe->next = large_head->next;
        large_probe->next = NULL;
        return small_head->next;
    }
};