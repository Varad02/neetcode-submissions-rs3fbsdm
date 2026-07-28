class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> adj(n + 1);
        for (auto e : times) {
            adj[e[0]].push_back({e[1], e[2]});
        }
        vector<int> dist(n + 1, INT_MAX);
        priority_queue<pair<int, int>, vector<pair<int, int>>,
                       greater<pair<int, int>>>
            q;
        q.push({0, k});
        dist[k] = 0;
        dist[0] = 0;
        while (!q.empty()) {
            auto [d, node] = q.top();
            q.pop();
            for (auto i : adj[node]) {
                if (dist[i.first] > d + i.second) {
                    dist[i.first] = d + i.second;
                    q.push({d + i.second, i.first});
                }
            }
        }
        int ans = 0;
        for (auto i : dist) {
            if (i == INT_MAX)
                return -1;
            ans = max(ans, i);
        }
        return ans;
    }
};