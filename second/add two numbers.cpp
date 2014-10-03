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
        int carry = 0;
        int curr = 0;
        ListNode *head = new ListNode(-1);
        ListNode *probe = head;
        while(l1 || l2 || carry) {
            if (l1) {
                carry += l1->val;
                l1 = l1->next;
            }
            if (l2) {
                carry += l2->val;
                l2 = l2->next;
            }
            ListNode *temp = new ListNode(carry%10);
            probe->next = temp;
            probe = probe->next;
            carry /= 10;
        }
        return head->next;
    }
};
