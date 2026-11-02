
class Solution {
public:

    vector<int> parent, sz;

    // Find with Path Compression
    int find(int x) {
        if(parent[x] == x)
            return x;

        return parent[x] = find(parent[x]);
    }

    // Union by Size
    long long unite(int u, int v) {

        u = find(u);
        v = find(v);

        if(u == v)
            return 0;

        // Attach smaller component to larger
        if(sz[u] < sz[v])
            swap(u, v);

        long long newPaths = 1LL * sz[u] * sz[v];

        parent[v] = u;
        sz[u] += sz[v];

        return newPaths;
    }

    vector<int> maximumWeight(
        int n,
        vector<vector<int>>& edges,
        vector<int>& queries
    ) {

        // Initialize DSU
        parent.resize(n + 1);
        sz.assign(n + 1, 1);

        for(int i = 1; i <= n; i++) {
            parent[i] = i;
        }

        // Sort edges by weight
        sort(edges.begin(), edges.end(),
             [](const vector<int>& a,
                const vector<int>& b) {
                 return a[2] < b[2];
             });

        // Store queries with original indices
        vector<pair<int, int>> q;

        for(int i = 0; i < queries.size(); i++) {
            q.push_back({queries[i], i});
        }

        sort(q.begin(), q.end());

        vector<int> ans(queries.size());

        int j = 0;
        long long totalPaths = 0;

        // Process queries in sorted order
        for(auto [limit, idx] : q) {

            // Add all eligible edges
            while(j < edges.size() &&
                  edges[j][2] <= limit) {

                totalPaths += unite(
                    edges[j][0],
                    edges[j][1]
                );

                j++;
            }

            ans[idx] = totalPaths;
        }

        return ans;
    }
};
