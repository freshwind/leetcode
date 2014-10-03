class Solution {
public:
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        ListNode *fake_head = new ListNode(-1);
        fake_head->next = head;
        ListNode *remove = fake_head;
        ListNode *probe = fake_head;
        for (int i = 0; i < n; ++i) {
            probe = probe->next;
        }
        while (probe->next) {
            probe = probe->next;
            remove = remove->next;
        }
        probe = remove->next;
        remove->next = probe->next;
        delete probe;
        return fake_head->next;
    }
};
