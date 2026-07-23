class Solution {
public:
    vector<bool> checkIfPrerequisite(int n, vector<vector<int>>& p,
                                     vector<vector<int>>& queries) {
        vector<vector<int>> adj(n + 1, vector<int>());
        vector<bool> ans;
        vector<vector<int>> dist(n + 1, vector<int>(n + 1, INT_MAX));
        for (auto i : p) {
            adj[i[0]].push_back(i[1]);
            dist[i[0]][i[1]] = 1;
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                for (int k = 0; k < n; k++) {
                    if (dist[i][k] != INT_MAX && dist[k][j] != INT_MAX)
                        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
        for (auto i : queries) {
            if (dist[i[0]][i[1]] == INT_MAX)
                ans.push_back(false);
            else
                ans.push_back(true);
        }
        return ans;
    }
};