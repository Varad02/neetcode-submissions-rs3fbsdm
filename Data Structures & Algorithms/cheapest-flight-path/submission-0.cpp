class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        unordered_map<int, vector<pair<int, int>>> adj;

        for (auto &edge : flights) {
            int src = edge[0];
            int dest = edge[1];
            int length = edge[2];
            adj[src].push_back({dest, length});
        }

        queue<vector<int>> pq;
        vector<int> dist(n+1, INT_MAX);
        pq.push({0, 0, src});
        dist[src] = 0;
        while(!pq.empty()) {
            int u = pq.front()[2];
            int s = pq.front()[0];
            int c = pq.front()[1];
            
            pq.pop();
            if (s>k) continue;
            for (auto x: adj[u]) {
                int v = x.first;
                int weight = x.second;
                if (dist[v] > c + weight and s<=k)
                {
                    dist[v] = c + weight;
                    pq.push({s+1, dist[v], v});
                }
            }
        }
        return dist[dst]==INT_MAX ? -1 : dist[dst];
    }
};