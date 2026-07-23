class Solution {
   public:
    bool BFS(vector<vector<int>>& adj, int n, int a, int b) {
        vector<int> vis(n, false);
        queue<int> q;
        q.push(a);
        bool is = false;
        while (not q.empty()) {
            int node = q.front();
            q.pop();
            if (node == b) {
                is = true;
                break;
            }
            if (vis[node]) continue;
            vis[node] = true;
            for (int i = 0; i < adj[node].size(); i++) q.push(adj[node][i]);
        }
        return is;
    }

    vector<bool> checkIfPrerequisite(int n, vector<vector<int>>& G, vector<vector<int>>& Q) {
        vector<bool> ans;
        vector<vector<int>> adj(n);
        for (auto g : G) adj[g[0]].push_back(g[1]);
        for (auto q : Q) ans.push_back(BFS(adj, n, q[0], q[1]));

        return ans;
    }
};