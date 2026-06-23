class Solution {
public:
    vector<vector<int>> dir = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

    int minimumEffortPath(vector<vector<int>>& h) {
        priority_queue<pair<int, pair<int, int>>,
                       vector<pair<int, pair<int, int>>>, greater<>>
            pq;
        int rows = h.size(), cols = h[0].size();
        vector<vector<int>> v(rows, vector<int>(cols, 0));
        pq.push({0, {0, 0}});
        while (pq.top().second != make_pair(rows - 1, cols - 1)) {
            auto [cost, rc] = pq.top();
            auto [row, col] = rc;
            pq.pop();
            if (v[row][col] == 1) continue;
            v[row][col] = 1;
            for (auto i : dir) {
                int n_r = row + i[0], n_c = col + i[1];
                if (n_r >= 0 and n_r < rows and n_c >= 0 and n_c < cols and
                    v[n_r][n_c] == 0) {
                    pq.push({max(cost, abs(h[row][col] - h[n_r][n_c])),
                             {n_r, n_c}});
                }
            }
        }
        return pq.top().first;
    }
};