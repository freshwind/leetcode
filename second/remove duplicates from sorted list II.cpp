class Solution {
public:
    ListNode *deleteDuplicates(ListNode *head) {
        ListNode *dummy_head = new ListNode(-1);
        dummy_head->next = head;
        ListNode *probe = dummy_head;
        ListNode *temp;
        while(probe->next) {
            temp = probe->next;
            if (!temp->next || temp->next->val != probe->next->val) {
                probe = probe->next;
            } else {
                temp = temp->next;
                while (temp->next && temp->next->val == probe->next->val) {
                    temp = temp->next;
                }
                probe->next = temp->next;
            }
        }
        return dummy_head->next;
    }
};