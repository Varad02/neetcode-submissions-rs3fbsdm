class Solution {
   public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> adj(n + 1);
        for (auto e : times) {
            adj[e[0]].push_back({e[1], e[2]});
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
        q.push({0, k});
        vector<bool> visited(n);
        int count = n;
        while (!q.empty()) {
            auto [d, node] = q.top();
            q.pop();
            if (visited[node - 1])
                continue;
            visited[node - 1] = true;
            if (--count == 0) {
                return d;
            }
            for (auto i : adj[node]) {
                if (!visited[i.first-1]) {
                    q.push({d + i.second, i.first});
                }
            }
        }
        return -1;
    }
};