#include "stdlib.h"
class Solution {
public:
    ListNode *insertionSortList(ListNode *head) {
        if (!head) return head;
        ListNode *fake_head = new ListNode(-1);
        while (head) {
            // cout <<head->val <<endl;
            ListNode *probe = fake_head;
            for (; probe->next; probe = probe->next) {
                if (probe->next->val >= head->val) {
                    ListNode *temp = head->next;
                    head->next = probe->next;
                    probe->next = head;
                    head = temp;
                    break;
                }
            }
            if (!probe->next) {
                probe->next = head;
                head = head->next;
                probe->next->next = NULL;
            }
            // cout <<probe->val <<endl;
            // print(fake_head);
        }
        return fake_head->next;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {3,4,1};
    ListNode *head = constructList(nums);
    head = sol.insertionSortList(head);
    // print(head);
}