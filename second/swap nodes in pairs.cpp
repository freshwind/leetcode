class Solution {
public:
    ListNode *swapPairs(ListNode *head) {
        ListNode *fake_head = new ListNode(-1);
        fake_head->next = head;
        ListNode *probe = fake_head;
        ListNode *middle;
        while (probe->next && probe->next->next) {
            middle = probe->next->next;
            probe->next->next = middle->next;
            middle->next = probe->next;
            probe->next = middle;
            probe = probe->next->next;
        }
        return fake_head->next;
    }
};