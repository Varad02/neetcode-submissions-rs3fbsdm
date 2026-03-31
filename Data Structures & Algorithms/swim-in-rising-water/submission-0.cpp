class Solution {
public:
    const int dx[4] = {0, 0, 1, -1};
    const int dy[4] = {1, -1, 0, 0};

    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> dist(n, vector<int>(n, INT_MAX));
        priority_queue<tuple<int,int,int>, vector<tuple<int,int,int>>, greater<>> pq;

        dist[0][0] = grid[0][0];
        pq.push({grid[0][0], 0, 0});

        while (!pq.empty()) {
            auto [cost, i, j] = pq.top(); pq.pop();

            if (i == n-1 && j == n-1) return cost;
            if (cost > dist[i][j]) continue;

            for (int d = 0; d < 4; d++) {
                int nx = i + dx[d];
                int ny = j + dy[d];
                if (nx >= 0 && nx < n && ny >= 0 && ny < n) {
                    int newCost = max(cost, grid[nx][ny]);
                    if (newCost < dist[nx][ny]) {
                        dist[nx][ny] = newCost;
                        pq.push({newCost, nx, ny});
                    }
                }
            }
        }
        return -1;
    }
};