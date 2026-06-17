class Solution {
public:
    int numSquares(int n) {
        vector<int> vis(n+1, 0);
        vis[n] = 1;
        int ps = 0;
        queue<int> q;
        q.push(n);
        while (!q.empty()) {
            int size = q.size();
            ps++;
            while (size--) {
                int curr = q.front();
                q.pop();
                for (int i = 1; i * i <= curr; i++) {
                    int next = curr - i*i;
                    if (next == 0) return ps;
                    if (!vis[next]) {
                        vis[next] = 1;
                        q.push(next);
                    }
                }
            }
        }
        return ps;
    }
};