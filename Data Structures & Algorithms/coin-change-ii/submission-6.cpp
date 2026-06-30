class Solution {
public:
    vector<vector<int>> dp;
    int util(int amount, int i, vector<int>& coins) {
        if (amount < 0)
            return 0;
        if (i == coins.size())
            return amount == 0 ? 1 : 0;
        if (dp[amount][i] != -1) return dp[amount][i];
        dp[amount][i] =
            util(amount, i + 1, coins) + util(amount - coins[i], i, coins);
        return dp[amount][i];
    }
    int change(int amount, vector<int>& coins) {
        dp.assign(amount + 1, vector<int>(coins.size() + 1, -1));
        return util(amount, 0, coins);
    }
};