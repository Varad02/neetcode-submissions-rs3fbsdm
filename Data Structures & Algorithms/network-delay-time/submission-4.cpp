class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> adj(n + 1);
        for (auto time : times) {
            adj[time[0]].push_back({time[1], time[2]});
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>,
                       greater<pair<int, int>>>
            pq;
        pq.push({0, k});
        vector<bool> visited(n + 1);
        while (!pq.empty()) {
            auto [dist, node] = pq.top();
            pq.pop();
            if (visited[node])
                continue;
            visited[node] = true;
            if (--n == 0)
                return dist;
            for (auto nei : adj[node]) {
                if (!visited[nei.first])
                    pq.push({dist + nei.second, nei.first});
            }
        }
        return -1;
    }
};
