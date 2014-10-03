/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode *sortedListToBST(ListNode *head) {
        ListNode *probe = head;
        int len = 0;
        while (probe) {
            len++;
            probe = probe->next;
        }
        return sortedListToBSTRecur(head, len);
    }

    TreeNode *sortedListToBSTRecur(ListNode *head, int len) {
        if (len == 0) return NULL;
        ListNode *probe = head;
        for (int i = 0; i < len/2; ++i) {
            probe = probe->next;
        }
        TreeNode *middle = new TreeNode(probe->val);
        middle->left = sortedListToBSTRecur(head, len/2);
        middle->right = sortedListToBSTRecur(probe->next, len - 1 - len/2);
        return middle;
    }
};