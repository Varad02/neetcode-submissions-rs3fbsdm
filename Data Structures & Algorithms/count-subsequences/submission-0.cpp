class Solution {
   public:
    vector<vector<int>> dp;
    int numDistinct(string s, string t) {
        dp.assign(s.length()+1, vector<int>(t.length()+1, -1));
        return util(s, t, 0, 0);
    }

    int util(string& s, string& t, int i, int j) {
        if (j == t.length()) return 1;
        if (i > s.length()) return 0;
        if (dp[i][j] != -1) return dp[i][j];
        int ans = 0;
        if (s[i] == t[j]) ans = util(s, t, i+1, j+1);
        ans += util(s, t, i+1, j);
        return dp[i][j] = ans;
    }
};
