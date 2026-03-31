class Solution {
public:
    vector<vector<int>> dp;
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        dp.assign(intervals.size(), vector<int>(intervals.size(), -1));
        return util(intervals, 0, 1, intervals.size());
    }
    int util(vector<vector<int>>& intervals, int i, int j, int n) {
        if (i >= n or j >= n)
            return 0;
        if (dp[i][j]!=-1) return dp[i][j];
        int x = INT_MAX, y = INT_MAX;
        if (intervals[i][1] > intervals[j][0]) {
            return dp[i][j] = 1 + min(util(intervals, i, j + 1, n), util(intervals, j, j+1, n));
        }
        else {
            return dp[i][j] = util(intervals, j, j+1, n);
        }
    }
};