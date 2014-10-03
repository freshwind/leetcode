
class Solution {
public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        ListNode *fake_head = new ListNode(-1);
        ListNode *p = fake_head;
        while (l1 && l2) {
            if (l1->val < l2->val) {
                l->next = l1;
                l1 = l1->next;
            } else {
                l->next = l2;
                l2 = l2->next;
            }
            p = p->next;
        }
        if (l1) p->next = l1;
        if (l2) p->next = l2;
        return fake_head->next;
    }
};

