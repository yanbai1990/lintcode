/**
 * Definition for Directed graph.
 * struct DirectedGraphNode {
 *     int label;
 *     vector<DirectedGraphNode *> neighbors;
 *     DirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution1 {
public:
    /**
     * @param graph: A list of Directed graph node
     * @return: Any topological order for the given graph.
     */
    vector<DirectedGraphNode*> topSort(vector<DirectedGraphNode*> graph) {
        // write your code here
        vector<DirectedGraphNode*> res;
        unordered_map<DirectedGraphNode*, int> indegree_map;
        bfs(graph, indegree_map);
        bfs(graph, indegree_map, res);
        return res;
    }
    
    void bfs(vector<DirectedGraphNode*> graph, unordered_map<DirectedGraphNode*, int> &indegree_map) {
        unordered_set<DirectedGraphNode*> visited;
        for(const auto node:graph) {
            if(visited.insert(node).second) {
                queue<DirectedGraphNode*> queue;
                queue.push(node);
                while(!queue.empty()) {
                    auto tmp=queue.front();
                    queue.pop();
                    for(const auto adj:tmp->neighbors) {
                        ++indegree_map[adj];
                        if(visited.insert(adj).second) {
                            queue.push(adj);
                        }
                    }
                }
            }
        }
    }
    
    void bfs(vector<DirectedGraphNode*> graph, unordered_map<DirectedGraphNode*, int> &indegree_map, vector<DirectedGraphNode*> &res) {
        queue<DirectedGraphNode*> queue;
        for(const auto node:graph) {
            if(indegree_map[node]==0) {
                queue.push(node);
            }
        }
        while(!queue.empty()) {
            auto node=queue.front();
            queue.pop();
            res.push_back(node);
            for(auto adj:node->neighbors) {
                --indegree_map[adj];
                if(indegree_map[adj]==0) {
                    queue.push(adj);
                }
            }
        }
    }
};

class Solution2 {
public:
    /**
     * @param graph: A list of Directed graph node
     * @return: Any topological order for the given graph.
     */
    vector<DirectedGraphNode*> topSort(vector<DirectedGraphNode*> graph) {
        // write your code here
        vector<DirectedGraphNode*> res;
        dfs(graph, res);
        reverse(res.begin(), res.end());
        return res;
    }
    
    void dfs(vector<DirectedGraphNode*> graph, vector<DirectedGraphNode*> &res) {
        unordered_set<DirectedGraphNode*> visited;
        for(const auto node:graph) {
            if(visited.insert(node).second) {
                dfsUtil(node, res, visited);
            }
        }
    }
    
    void dfsUtil(DirectedGraphNode* node, vector<DirectedGraphNode*> &res, unordered_set<DirectedGraphNode*> &visited) {
        auto neighbors=node->neighbors;
        for(auto neighbor:neighbors) {
            if(visited.insert(neighbor).second) {
                dfsUtil(neighbor, res, visited);
            }
        }
        res.push_back(node);
    }
};

