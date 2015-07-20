/**
 * Definition for Undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
public:
    /**
     * @param nodes a array of Undirected graph node
     * @return a connected set of a Undirected graph
     */
    vector<vector<int>> connectedSet(vector<UndirectedGraphNode*>& nodes) {
        // Write your code here
        vector<vector<int> > result;
        vector<int> path;
        
        if(nodes.empty()) return result;
        dfs(nodes, result, path);
        return result;
    }
    
    void dfs(vector<UndirectedGraphNode*> nodes, vector<vector<int> > &result, vector<int> &path) {
        unordered_set<UndirectedGraphNode*> visited;
        for(auto node:nodes) {
            if(visited.insert(node).second) {
                path.push_back(node->label);
                dfsUtil(node, visited, result, path);
                sort(begin(path), end(path));
                result.push_back(path);
                path.clear();
            }
        }
    }
    
    void dfsUtil(UndirectedGraphNode* node, unordered_set<UndirectedGraphNode*> &visited, vector<vector<int> > &result, vector<int> &path) {
        for(auto neighbor:node->neighbors) {
            if(visited.insert(neighbor).second) {
                path.push_back(neighbor->label);
                dfsUtil(neighbor, visited, result, path);
            }
        }
        
    }
};
