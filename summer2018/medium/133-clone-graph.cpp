// 28ms
/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
private:
    unordered_map<int, UndirectedGraphNode*> created;
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if(!node) return nullptr;
        queue<UndirectedGraphNode *> toVisit;
        toVisit.push(node);
        UndirectedGraphNode *ans = new UndirectedGraphNode(node->label);
        created[node->label] = ans;
        while(!toVisit.empty()){
            UndirectedGraphNode *cur = toVisit.front();
            toVisit.pop();
            UndirectedGraphNode* curCopy = created[cur->label];
            UndirectedGraphNode* neighborCopy;
            for(int i=0; i<cur->neighbors.size(); ++i){
                if(created.count(cur->neighbors[i]->label)==0){
                    neighborCopy = new UndirectedGraphNode(cur->neighbors[i]->label);
                    toVisit.push(cur->neighbors[i]);
                    created[cur->neighbors[i]->label] = neighborCopy;
                }
                else{
                    neighborCopy = created[cur->neighbors[i]->label];
                }
                curCopy->neighbors.push_back(neighborCopy);
            }
        }
        return ans;
    }
};
