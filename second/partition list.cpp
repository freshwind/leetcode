class Solution {
public:
    ListNode *partition(ListNode *head, int x) {
        ListNode *small = new ListNode(-1);
        ListNode *big = new ListNode(-1);
        ListNode *small_probe = small;
        ListNode *big_probe = big;
        while(head) {
            if(head->val < x) {
                small_probe->next = head;
                small_probe = small_probe->next;
            } else {
                big_probe->next = head;
                big_probe = big_probe->next;
            }
            head = head->next;
        }
        small_probe->next = big->next;
        big_probe->next = NULL;
        return small->next;
    }
};
