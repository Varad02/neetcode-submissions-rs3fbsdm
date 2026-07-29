class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& p) {
        int n = p.size();
        vector<vector<pair<int, int>>> adj(n);
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int dist = abs(p[i][0] - p[j][0]) + abs(p[i][1] - p[j][1]);
                adj[i].push_back({j, dist});
                adj[j].push_back({i, dist});
            }
        }
        vector<int> distance(n, INT_MAX);
        priority_queue<pair<int, int>, vector<pair<int, int>>,
                       greater<pair<int, int>>>
            pq;
        pq.push({0, 0});
        vector<bool> visited(n);
        int ans = 0;
        while (!pq.empty()) {
            auto [dist, node] = pq.top();
            pq.pop();
            if (visited[node])
                continue;
            visited[node] = true;
            ans += dist;
            for (auto [ne, d] : adj[node]) {
                if (!visited[ne] && d < distance[ne]) {
                    distance[ne] = d;
                    pq.push({d, ne});
                }
            }
        }
        return ans;
    }
};
