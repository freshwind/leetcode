class Solution {
public:
    ListNode *mergeKList(vector<ListNode *> &lists) {

    }
};/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
struct myclass {
    bool operator() (ListNode *a, ListNode *b) { return (a->val < b->val);}
} myCompareObject;

class Solution {
public:
    int findPosition (vector<ListNode *> &sorted_vector, ListNode *t) {
        int begin = 0;
        int end = sorted_vector.size();
        int middle;
        while (begin < end) {
            middle = (begin+end)/2;
            if (sorted_vector[middle]->val == t->val) {
                return middle;
            } else if (sorted_vector[middle]->val < t->val) {
                begin = middle+1;
            } else {
                end = middle;
            }
        }
        return begin;
    }

    ListNode *mergeKLists(vector<ListNode *> &lists) {
        if (lists.size() == 0) return NULL;
        if (lists.size() == 1) return lists[0];
        ListNode *fake_head = new ListNode(-1);
        ListNode *probe = fake_head;
        ListNode *temp;
        int index;
        vector<ListNode *> sorted_temp;
        for (int i = 0; i < lists.size(); ++i) {
            if (lists[i] != NULL) {
                sorted_temp.push_back(lists[i]);
            }
        }

        sort(sorted_temp.begin(), sorted_temp.end(), myCompareObject);
        while(!sorted_temp.empty()) {
            probe->next = sorted_temp[0];
            probe = probe->next;
            temp = sorted_temp[0]->next;
            sorted_temp.erase(sorted_temp.begin());
            if (temp != NULL) {
                index = findPosition(sorted_temp, temp);
                sorted_temp.insert(sorted_temp.begin()+index, temp);
            }
        }
        return fake_head->next;
    }
};