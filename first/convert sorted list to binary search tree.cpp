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
        if (head == NULL) {
            return NULL;
        }
        ListNode *list_probe = head;
        int length = 0;
        while(list_probe != NULL) {
            list_probe = list_probe->next;
            length++;
        }
        // vector<int> list;
        // ListNode *listProbe = head;
        // while(listProbe != NULL) {
        //     list.push_back(listProbe->val);
        // }
        return sortedListToBSTRecur(0, length-1, head);
    }

    TreeNode *sortedListToBSTRecur(int start, int end, ListNode *head) {
        if (end<start) {
            return NULL;
        }
        int middle = (start + end + 1)/2;
        ListNode *list_probe = head;
        for(int i = 0; i != middle; ++i) {
            list_probe = list_probe->next;
        }
        TreeNode *middle_node = new TreeNode(0);
        middle_node->val = list_probe->val;
        middle_node->left = sortedListToBSTRecur(start, middle-1, head);
        middle_node->right = sortedListToBSTRecur(middle+1, end, head);
        return middle_node;
    }

    TreeNode *sortedListToBSTRecurWithMemoryLimitExceeded(int start, int end, vector<int> &list) {
        if (end>start) {
            return NULL;
        }
        int middle = (start+end+1)/2;
        TreeNode *middleNode = new TreeNode(0);
        middleNode->val = list[middle];
        middleNode->left = sortedListToBSTRecurWithMemoryLimitExceeded(start, middle-1, list);
        middleNode->right = sortedListToBSTRecurWithMemoryLimitExceeded(middle+1, end, list);
        return middleNode;
    }
};