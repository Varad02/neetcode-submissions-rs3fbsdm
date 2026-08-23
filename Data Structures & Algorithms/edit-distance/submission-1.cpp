class Solution {
   public:
    vector<vector<int>> dp;
    int minDistance(string word1, string word2) {
        dp.assign(word1.length() + 1, vector<int>(word2.length() + 1, -1));
        return util(word1, word2, 0, 0);
    }

    int util(string& word1, string& word2, int i, int j) {
        int n = word1.length(), m = word2.length();
        if (i == n) return m - j;
        if (j == m) return n - i;
        if (dp[i][j] != -1) return dp[i][j];
        if (word1[i] == word2[j]) return dp[i][j] = util(word1, word2, i + 1, j + 1);
        return dp[i][j] =
                   1 + min(util(word1, word2, i + 1, j),
                           min(util(word1, word2, i + 1, j + 1), util(word1, word2, i, j + 1)));
    }
};