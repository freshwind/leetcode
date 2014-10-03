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
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        ListNode dummyHead(0);
        dummyHead.next = head;
        ListNode *fastp = &dummyHead;
        ListNode *slowp = &dummyHead;
        for (int i = 0; i < n; ++i) {
            fastp = fastp->next;
        }
        while (fastp->next != NULL) {
            fastp = fastp->next;
            slowp = slowp->next;
        }
        slowp->next  = slowp->next->next;
        return dummyHead.next;
    }
};