/**
 * Definition for Directed graph.
 * struct DirectedGraphNode {
 *     int label;
 *     vector<DirectedGraphNode *> neighbors;
 *     DirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
public:
    /**
     * @param nodes a array of directed graph node
     * @return a connected set of a directed graph
     */
    vector<vector<int>> connectedSet2(vector<DirectedGraphNode*>& nodes) {
        // Write your code here
        sort(nodes.begin(), nodes.end(), [](const DirectedGraphNode *a, const DirectedGraphNode *b){
            return a->label<b->label;
        });
        
        unordered_map<int, int> father;
        for(const auto node:nodes) {
            father[node->label]=node->label;
        }
        
        for(const auto node:nodes) {
            for(const auto neighbor:node->neighbors) {
                make_set(father, node->label, neighbor->label);
            }
        }
        
        unordered_map<int, vector<int>> group;
        for(const auto node:nodes) {
            group[find_set(father, node->label)].push_back(node->label);
        }
        
        vector<vector<int> > result;
        for(const auto g:group) {
            result.push_back(move(g.second));
        }
        
        return result;
    }
    
    int find_set(unordered_map<int, int> &father, int x) {
        if(x!=father[x]) {
            father[x]=find_set(father, father[x]);
        }
        return father[x];
    }
    
    void make_set(unordered_map<int, int> &father, int x, int y) {
        x=find_set(father, x);
        y=find_set(father, y);
        if(x==y) return;
        else if(x>y) father[y]=x;
        else father[x]=y;
    }
    
};
