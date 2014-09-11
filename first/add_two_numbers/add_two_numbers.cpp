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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        int temp_sum = l1->val + l2->val;
        int gain = 0;
        if (temp_sum >= 10) {
            temp_sum -= 10;
            gain = 1;
        }
        ListNode *l3 = new ListNode(temp_sum);
        ListNode *l3_probe = l3;
        l1 = l1->next;
        l2 = l2->next;
        while (l1!=NULL || l2!=NULL) {
            temp_sum = gain;
            gain = 0;
            if (l1!=NULL) {
                temp_sum += l1->val;
                l1 = l1->next;
            }
            if (l2!=NULL) {
                temp_sum += l2->val;
                l2 = l2->next;
            }
            if (temp_sum >= 10) {
                temp_sum -= 10;
                gain = 1;
            }
            ListNode *temp_node = new ListNode(temp_sum);
            l3_probe->next = temp_node;
            l3_probe = temp_node;
        }
        if (gain > 0) {
            ListNode *temp_node = new ListNode(1);
            l3_probe->next = temp_node;
        }
        return l3;
    }
};