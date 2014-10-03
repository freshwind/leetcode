/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if (node == NULL) {
            return NULL;
        }
        vector<UndirectedGraphNode *> visited_nodes;
        return cloneGraphRecur(node, visited_nodes);
    }

    UndirectedGraphNode *cloneGraphRecur(UndirectedGraphNode *node,
                                         vector<UndirectedGraphNode *> &visited_nodes) {
        UndirectedGraphNode *new_node = new UndirectedGraphNode(node->label);
        visited_nodes.push_back(new_node);
        int index;
        for (int i = 0; i != node->neighbors.size(); ++i) { //for each neighbors
            index = isFound(visited_nodes, node->neighbors[i]->label);
            if (index != -1) {
                new_node->neighbors.push_back(visited_nodes[index]);
            } else {
                new_node->neighbors.push_back(cloneGraphRecur(node->neighbors[i], visited_nodes));
            }
        }
        return new_node;
    }

    int isFound(vector<UndirectedGraphNode *> visited_list, int label) {
        for(int i = 0; i != visited_list.size(); ++i) {
            if (visited_list[i]->label == label) {
                return i;
            }
        }
        return -1;
    }
};