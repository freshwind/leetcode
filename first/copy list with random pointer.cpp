/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        if (head == NULL) return NULL;
        unordered_map<int, RandomListNode *> node_map;
        unordered_map<int, RandomListNode *>::const_iterator got;
        RandomListNode *new_head = new RandomListNode(head->label);
        RandomListNode *new_probe = new_head;
        RandomListNode *probe = head;
        RandomListNode *new_temp;
        node_map.insert({new_head->label, new_head});
        while (probe != NULL) { //copy pointer of current probe
            if (probe->next != NULL) {
                //copy probe->next
                got = node_map.find(probe->next->label);
                if (got == node_map.end()) {
                    new_temp = new RandomListNode(probe->next->label);
                    new_probe->next = new_temp;
                    node_map.insert( {new_temp->label, new_temp});
                } else {
                    new_probe->next = got->second;
                }
            }
            if (probe->random != NULL) {
                //copu probe->random
                got = node_map.find(probe->random->label);
                if (got == node_map.end()) {
                    new_temp = new RandomListNode(probe->random->label);
                    new_probe->random = new_temp;
                    node_map.insert({new_temp->label, new_temp});
                } else {
                    new_probe->random = got->second;
                }
            }
            probe = probe->next;
            new_probe = new_probe->next;
        }
        return new_head;
    }
};