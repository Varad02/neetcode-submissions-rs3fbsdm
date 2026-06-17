class Solution {
   public:
    int numSquares(int n) {
        vector<vector<int>> dp(sqrt(n) + 1, vector<int>(n+1, 0));
        return util(n, dp, sqrt(n));
    }

    int util(int n, vector<vector<int>>& dp, int i) {
        if (dp[i][n]) return dp[i][n];
        if (n==0) return 0;
        if (i != 1)
            return dp[i][n] = min(1 + util(n - (i * i), dp, sqrt(n - (i * i))), util(n, dp, i - 1));
        else
            return n;
    }
};