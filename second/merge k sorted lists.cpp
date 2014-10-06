
class Solution {
private:
    class myCmp {
    public:
        bool operator()(const ListNode *a, const ListNode *b) const {
            return a->val > b->val;
        }
    };
public:
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        priority_queue<ListNode *, vector<ListNode *>, myCmp> Q;
        for (int i = 0; i < lists.size(); ++i) {
            if (lists[i])
                Q.push(lists[i]);
        }
        ListNode *head = new ListNode(-1);
        ListNode *probe = head;
        while(!Q.empty()) {
            ListNode *temp = Q.top();
            probe->next = temp;
            probe = probe->next;
            Q.pop();
            if (temp->next) {
                Q.push(temp->next);
            }
        }
        return head->next;
    }
};

