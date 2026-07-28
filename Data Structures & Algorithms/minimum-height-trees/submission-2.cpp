class Solution {
   public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if (n == 1) return {0};
        if (n == 2) return edges[0];
        vector<vector<int>> adj(n, vector<int>());
        vector<int> degree(n, 0);
        for (auto edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
            degree[edge[0]]++;
            degree[edge[1]]++;
        }
        queue<int> q;
        int remainingNumber = n;
        for (int i = 0; i < n; i++) {
            if (degree[i] == 1) {
                q.push(i);
            }
        }
        while (remainingNumber > 2) {
            int qSize = q.size();
            remainingNumber -= qSize;
            for (int i = 0; i < qSize; i++) {
                int node = q.front();
                q.pop();
                degree[node]--;
                for (int j : adj[node]) {
                    if (--degree[j] == 1) {
                        q.push(j);
                    }
                }
            }
        }
        vector<int> ans;
        while (!q.empty()) {
            ans.push_back(q.front());
            q.pop();
        }
        return ans;
    }
};