class Solution {
public:
    unordered_set<int> col, nD, pD;
    vector<vector<string>> ans;

    vector<vector<string>> solveNQueens(int n) {
        vector<string> board;
        util(0, n, board);
        return ans;
    }

    void util(int c, int n, vector<string> &board) {
        if (c == n) {
            ans.push_back(board);
            return;
        }
        string curr(n, '.');
        for (int i = 0; i < n; i++) {
            if (!col.count(i) && !nD.count(i-c) && !pD.count(i+c)) {
                col.insert(i);
                nD.insert(i-c);
                pD.insert(i+c);
                curr[i] = 'Q';
                board.push_back(curr);
                util(c+1, n, board);
                curr[i] = '.';
                board.pop_back();
                col.erase(i);
                nD.erase(i-c);
                pD.erase(i+c);
            }
        }
    }
};