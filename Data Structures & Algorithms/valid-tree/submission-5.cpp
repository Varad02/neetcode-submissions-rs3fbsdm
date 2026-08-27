class Solution {
   public:
    bool validTree(int n, vector<vector<int>>& edges) {
        unordered_map<int, vector<int>> adj;
        for (auto i : edges) {
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }
        vector<int> vis(n, 0);
        queue<pair<int, int>> q;
        q.push({0, -1});
        while (!q.empty()) {
            auto [c, p] = q.front();
            vis[c] = 1;
            q.pop();
            for (int i : adj[c]) {
                if (p == i) continue;
                if (vis[i]) return false;
                q.push({i, c});
                // vis[i] = 1;
            }
        }
        for (int i : vis)
            if (!i) return false;
        return true;
    }
};
