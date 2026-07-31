class Solution {
public:
    vector<vector<int>> buildMatrix(int n, vector<vector<int>>& rowConditions,
                                    vector<vector<int>>& colConditions) {
        vector<vector<int>> matrix(n, vector<int>(n, 0));
        vector<vector<int>> rowAdj(n + 1);
        vector<int> rowInDegree(n + 1, 0);
        vector<vector<int>> colAdj(n + 1);
        vector<int> colInDegree(n + 1);
        for (auto i : rowConditions) {
            rowAdj[i[0]].push_back(i[1]);
            rowInDegree[i[1]]++;
        }
        for (auto i : colConditions) {
            colAdj[i[0]].push_back(i[1]);
            colInDegree[i[1]]++;
        }
        queue<int> q;
        vector<int> row(n + 1, -1);
        for (int i = 1; i <= n; i++)
            if (rowInDegree[i] == 0)
                q.push(i);
        int r = 0;
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            row[node] = r;
            r++;
            for (auto i : rowAdj[node]) {
                if (--rowInDegree[i] == 0)
                    q.push(i);
            }
        }
        queue<int> qCol;
        vector<int> col(n + 1, -1);
        for (int i = 1; i <= n; i++)
            if (colInDegree[i] == 0)
                qCol.push(i);
        int c = 0;
        while (!qCol.empty()) {
            int node = qCol.front();
            qCol.pop();
            col[node] = c;
            c++;
            for (auto i : colAdj[node]) {
                if (--colInDegree[i] == 0)
                    qCol.push(i);
            }
        }
        for (int i = 1; i <= n; i++) {
            if (row[i] == -1 || col[i] == -1 || matrix[row[i]][col[i]] != 0)
                return {};
            matrix[row[i]][col[i]] = i;
        }

        return matrix;
    }
};