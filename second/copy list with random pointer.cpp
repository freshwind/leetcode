#include "stdlib.h"
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
        unordered_map<RandomListNode *, RandomListNode *> nodes;
        unordered_map<RandomListNode *, RandomListNode *>::const_iterator got;
        RandomListNode *new_head;
        RandomListNode *new_node;
        if (head) {
            new_head = new RandomListNode(head->label);
            new_node = new_head;
        } else {
            return NULL;
        }
        while (1) {
            if (head->random) {
                got = nodes.find(head->random);
                if (got == nodes.end()) {
                    new_node->random = new RandomListNode(head->random->label);
                    nodes[head->random] = new_node->random;
                } else {
                    new_node->random = got->second;
                }
            }
            if (head->next) {
                got = nodes.find(head->next);
                if (got == nodes.end()) {
                    new_node->next = new RandomListNode(head->next->label);
                    nodes[head->next] = new_node->next;
                } else {
                    new_node->next = got->second;
                }
            } else {
                return new_head;
            }
            head = head->next;
            new_node = new_node->next;
        }
    }
};

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
        if (!head) return NULL;
        RandomListNode *probe = head;
        RandomListNode *new_node;
        while (probe) {
            new_node = new RandomListNode(probe->label);
            new_node->next = probe->next;
            probe->next = new_node;
            probe = new_node->next;
        }
        probe = head;
        while (probe) {
            probe->next->random = probe->random ? probe->random->next : NULL;
            probe = probe->next->next;
        }
        RandomListNode *new_head = head->next;
        //-1 -1 1 1
        probe = head->next;
        while (head->next->next) {
            head->next = probe->next;
            head = head->next;
            probe->next = head->next;
            probe = probe->next;
        }
        head->next = NULL;
        return new_head;
    }
};



int main() {
    return 0;
}
