class Solution {
public:
    vector<vector<int>> dp;
    int longestCommonSubsequence(string text1, string text2) {
        dp.assign(text1.length(), vector<int>(text2.length(), 0));
        return util(text1, text2, 0, 0);
    }
    int util(string text1, string text2, int i, int j) {
        if (j == text2.length() or i == text1.length()) return 0;
        if (dp[i][j] != 0) return dp[i][j];
        if (text1[i] == text2[j]) return dp[i][j] = 1 + util(text1, text2, i+1, j+1);
        else return dp[i][j] = max(util(text1, text2, i+1, j), util(text1, text2, i, j+1));
    }
};
