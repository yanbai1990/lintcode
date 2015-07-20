/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution1 {
public:
    /**
     * @param node: A undirected graph node
     * @return: A undirected graph node
     */
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        // write your code here
        if(node==NULL) return node;
        unordered_map<UndirectedGraphNode*, UndirectedGraphNode*> copys;
        UndirectedGraphNode* res = dfs(node, copys);
        return res;
    }
    
    UndirectedGraphNode* dfs(UndirectedGraphNode *node, unordered_map<UndirectedGraphNode*, UndirectedGraphNode*> &copys) {
        UndirectedGraphNode *new_node=new UndirectedGraphNode(node->label);
        copys[node]=new_node;
        for(auto neighbor:node->neighbors) {
            if(copys.find(neighbor)==copys.end()) {
                new_node->neighbors.push_back(dfs(neighbor, copys));
            } else {
                new_node->neighbors.push_back(copys[neighbor]);
            }
        }
        return new_node;
    }
};

class Solution2 {
public:
    /**
     * @param node: A undirected graph node
     * @return: A undirected graph node
     */
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        // write your code here
        if(node==NULL) return node;
        
        unordered_map<UndirectedGraphNode*, UndirectedGraphNode*> copys;
        queue<UndirectedGraphNode*> visited;
        
        copys[node]=new UndirectedGraphNode(node->label);
        visited.push(node);
        
        while(!visited.empty()) {
            auto node=visited.front();
            visited.pop();
            
            for(auto neighbor:node->neighbors) {
                if(copys.find(neighbor)==copys.end()) {
                    copys[neighbor]=new UndirectedGraphNode(neighbor->label);
                    visited.push(neighbor);
                }
                copys[node]->neighbors.push_back(copys[neighbor]);
            }
        }
        
        return copys[node];
    }
};

