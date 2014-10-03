class Solution {
public:
    ListNode *reverseBetween(ListNode *head, int m, int n) {
        ListNode *fake_head = new ListNode(-1);
        fake_head->next = head;
        ListNode *probe = fake_head;
        int i = 0;
        for(; i < m-1; ++i) {
            probe = probe->next;
        }
        ListNode *start = probe;
        probe = probe->next;
        for(int j = 0; j < n-m; ++j) {
            ListNode *temp = probe->next;
            probe->next = temp->next;
            temp->next = start->next;
            start->next = temp;
        }
        return fake_head->next;
    }
};