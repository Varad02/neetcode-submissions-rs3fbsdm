class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<int> res;
        int i = 0, j = 0;
        int x = 0, y = 0;
        int count = 0;
        while (true) {
            for (; j < n - y; j++) {
                if (count == m * n)
                    break;
                cout << matrix[i][j] << " ";
                res.push_back(matrix[i][j]);
                count++;
            }
            j--;
            i++;
            for (; i < m - x; i++) {
                if (count == m * n)
                    break;
                res.push_back(matrix[i][j]);
                cout << matrix[i][j] << " ";
                count++;
            }
            i--;
            j--;
            for (; j >= y; j--) {
                if (count == m * n)
                    break;
                res.push_back(matrix[i][j]);
                cout << matrix[i][j] << " ";
                count++;
            }
            j++;
            i--;
            for (; i > x; i--) {
                if (count == m * n)
                    break;
                cout << matrix[i][j] << " ";
                res.push_back(matrix[i][j]);
                count++;
            }
            if (count == m * n)
                break;
            i++;
            j++;
            x++;
            y++;
        }
        return res;
    }
};
