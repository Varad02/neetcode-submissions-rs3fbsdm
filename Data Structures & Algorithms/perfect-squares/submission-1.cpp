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
                int cur = q.front();
                q.pop();
                for (int i = 1; i * i <= cur; i++) {
                    int nxt = cur - i * i;
                    if (nxt == 0) {
                        return ps;
                    }
                    if (!vis[nxt]) {
                        vis[nxt] = true;
                        q.push(nxt);
                    }
                }
            }
        }
        return ps;
    }
};