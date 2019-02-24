// BFS

class Solution {
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if (!node) {
            return NULL;
        }
        UndirectedGraphNode* copy = new UndirectedGraphNode(node -> label);
        copies[node] = copy;
        queue<UndirectedGraphNode*> todo;
        todo.push(node);
        while (!todo.empty()) {
            UndirectedGraphNode* cur = todo.front();
            todo.pop();
            for (UndirectedGraphNode* neighbor : cur -> neighbors) {
                if (copies.find(neighbor) == copies.end()) {
                    copies[neighbor] = new UndirectedGraphNode(neighbor -> label);
                    todo.push(neighbor);
                }
                copies[cur] -> neighbors.push_back(copies[neighbor]);
            }
        }
        return copy;
    }
private:
    unordered_map<UndirectedGraphNode*, UndirectedGraphNode*> copies;
};

// DFS
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
        if (!node) {
            return NULL;
        }
        if (copies.find(node) == copies.end()) {
            copies[node] = new UndirectedGraphNode(node -> label);
            for (UndirectedGraphNode* neighbor : node -> neighbors) {
                copies[node] -> neighbors.push_back(cloneGraph(neighbor));
            }
        }
        return copies[node];
    }
private:
    unordered_map<UndirectedGraphNode*, UndirectedGraphNode*> copies;
};
