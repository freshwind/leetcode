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
    ListNode *insertionSortList(ListNode *head) {
        if (head == NULL) {
            return head;
        }
        ListNode *probe = head->next;
        ListNode *sorted_head = new ListNode(-1);
        sorted_head->next = head;
        ListNode *sorted_probe;
        head->next = NULL;
        while (probe != NULL) {
            sorted_probe = sorted_head->next;
            if (probe->val <= sorted_probe->val) {//insert at start
                sorted_head->next = probe;
                probe = probe->next;
                sorted_head->next->next = sorted_probe;
            } else {
                while (sorted_probe->next != NULL &&
                       sorted_probe->next->val <= probe->val) {
                    sorted_probe = sorted_probe->next;
                }
                if (sorted_probe->next == NULL) { //insert at last
                    sorted_probe->next = probe;
                    probe = probe->next;
                    sorted_probe->next->next = NULL;
                } else { //insert at last
                    ListNode *temp_node = probe->next;
                    probe->next = sorted_probe->next;
                    sorted_probe->next = probe;
                    probe = temp_node;
                }
            }
        }
        return sorted_head->next;
    }
};