class Solution {
public:
    int maxEdgesToAdd(int V, vector<vector<int>>& edges) {
        vector<vector<int>> graph(V);
        vector<int> indegree(V, 0);
        for (auto& e : edges) {
            graph[e[0]].push_back(e[1]);
            indegree[e[1]]++;
        }
        queue<int> q;
        for (int i = 0; i < V; i++) if (indegree[i] == 0) q.push(i);
        vector<int> topo;
        while (!q.empty()) {
            int node = q.front(); q.pop();
            topo.push_back(node);
            for (int nei : graph[node]) {
                indegree[nei]--;
                if (indegree[nei] == 0) q.push(nei);
            }
        }
        vector<vector<bool>> reachable(V, vector<bool>(V, false));
        function<void(int,int)> dfs = [&](int src, int node) {
            for (int nei : graph[node]) {
                if (!reachable[src][nei]) {
                    reachable[src][nei] = true;
                    dfs(src, nei);
                }
            }
        };
        for (int i = 0; i < V; i++) dfs(i, i);
        vector<int> pos(V);
        for (int i = 0; i < V; i++) pos[topo[i]] = i;
        int count = 0;
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                if (i != j && pos[i] < pos[j] && !reachable[j][i]) {
                    if (find(graph[i].begin(), graph[i].end(), j) == graph[i].end())
                        count++;
                }
            }
        }
        return count;
    }
};

