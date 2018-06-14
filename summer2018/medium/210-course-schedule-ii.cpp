// 16ms
class Solution {
public:
    vector<int> res;
    int ans;
    void dfs(int n, vector<int> &v, vector<vector<int>> &graph){
        v[n] = 1;
        for(int i=0; i<graph[n].size(); i++){
            if(v[graph[n][i]] == 1)
                return;
            else if(v[graph[n][i]] == 0){
                dfs(graph[n][i], v, graph);
            }
        }
        v[n] = 2;
        ans--;
        res[ans] = n;
        return;
    }
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
        res.assign(numCourses, 0);
        ans = numCourses;
        vector<int> v(numCourses);
        vector<vector<int>> graph(numCourses);
        queue<int> q;
        for(int i=0; i<prerequisites.size(); i++){
            graph[prerequisites[i].second].push_back(prerequisites[i].first);
        }
        for(int i=0; i<v.size(); i++){
           if(v[i] == 0)
               dfs(i, v, graph);
        }
        return ans == 0 ? res : vector<int>(0);
    }
};


// DFS
class Solution {
public:
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<unordered_set<int>> graph = make_graph(numCourses, prerequisites);
        vector<int> degrees = compute_indegree(graph);
        queue<int> zeros;
        for (int i = 0; i < numCourses; i++)
            if (!degrees[i]) zeros.push(i);
        vector<int> toposort;
        for (int i = 0; i < numCourses; i++) {
            if (zeros.empty()) return {};
            int zero = zeros.front();
            zeros.pop();
            toposort.push_back(zero);
            for (int neigh : graph[zero]) {
                if (!--degrees[neigh])
                    zeros.push(neigh);
            }
        }
        return toposort;
    }
private:
    vector<unordered_set<int>> make_graph(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<unordered_set<int>> graph(numCourses);
        for (auto pre : prerequisites)
            graph[pre.second].insert(pre.first);
        return graph; 
    }
    vector<int> compute_indegree(vector<unordered_set<int>>& graph) {
        vector<int> degrees(graph.size(), 0);
        for (auto neighbors : graph)
            for (int neigh : neighbors)
                degrees[neigh]++;
        return degrees;
    }
};
