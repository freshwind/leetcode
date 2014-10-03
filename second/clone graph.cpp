class Solution {
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        return dfs(node);
    }
private:
    unordered_map<int, UndirectedGraphNode *> map;
    unordered_map<int, UndirectedGraphNode *>::const_iterator got;
    UndirectedGraphNode *dfs(UndirectedGraphNode *node) {
        if (!node) return NULL;
        got = map.find(node->label);
        if (got != map.end()) {
            return got->second;
        } else {
            UndirectedGraphNode *new_node = new UndirectedGraphNode(node->label);
            map[new_node->label] = new_node;
            for (int i = 0; i < node->neighbors.size(); ++i) {
                new_node->neighbors.push_back(dfs(node->neighbors[i]));
            }
            return new_node;
        }
    }
};
