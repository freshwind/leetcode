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
    ListNode *reverseKGroup(ListNode *head, int k) {
        if (k == 1) return head;
        ListNode *fake_head = new ListNode(-1);
        fake_head->next = head;
        ListNode *group_tail = fake_head;
        ListNode *probe = group_tail;
        ListNode *reverse_start;
        ListNode *reverse_probe;
        ListNode *temp;
        while (probe != NULL) {
            //search new group_tail
            int i = 0;
            for(; i < k && probe != NULL; ++i) {
                probe = probe->next;
            }

            //if not found
            if (probe == NULL) {
                return fake_head->next;
            } else {//if found
                reverse_start = group_tail->next;
                group_tail->next = probe;
                group_tail = reverse_start;
                reverse_probe = reverse_start->next;
                reverse_start->next = probe->next;
                temp = reverse_probe->next;
                reverse_probe->next = reverse_start;
                for(int j = 0; j < k-2; ++j) {
                    reverse_start = reverse_probe;
                    reverse_probe = temp;
                    temp = temp->next;
                    reverse_probe->next = reverse_start;
                }
                probe = group_tail;
            }
        }
        return fake_head->next;
    }
};