class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n+1, vector<int>());
        for (auto i: edges) {
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }
        vector<int> components(n, 0);
        int c = 1;
        for (int i = 0; i < n; i++) {
            if (components[i] != 0)
                continue;
            queue<int> q;
            q.push(i);
            while (!q.empty()) {
                int node = q.front(); q.pop();
                components[node] = c;
                for (auto j: adj[node]) {
                    if (components[j] == 0) q.push(j);
                }
            }
            c++;
        }
        return c-1;
    }
};
