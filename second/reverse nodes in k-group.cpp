#include "stdlib.h"

class Solution {
public:
    ListNode *reverseKGroup(ListNode *head, int k) {
        ListNode *fake_head = new ListNode(-1);
        fake_head->next = head;
        ListNode *probe = fake_head;
        ListNode *temp, *next_start, *temp2;
        while (probe->next) {
            next_start = probe->next;
            for (int i = 0; i < k; i++) {
                if (!next_start) return fake_head->next;
                next_start = next_start->next;
            }
            temp = probe->next;
            while (temp->next != next_start) {
                temp2 = probe->next;
                probe->next = temp->next;
                temp->next = temp->next->next;
                probe->next->next = temp2;
            }
            probe = temp;
            // probe->k nodes -> temp
            // probe-> temp ->(temp next) ->...
        }
        return fake_head->next;
    }
};

int main() {
    vector<int> nums = {1,2,3,4,5};
    ListNode *head = constructList(nums);
    Solution sol;
    print(sol.reverseKGroup(head, 3));
}