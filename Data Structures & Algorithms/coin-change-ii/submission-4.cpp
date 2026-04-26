class Solution {
public:
    vector<vector<int>> dp;
    int change(int amount, vector<int>& coins) {
        dp.assign(amount+1, vector<int>(coins.size()+1, -1));
        return util(amount, coins, 0);
    }

    int util(int amount, vector<int>& coins, int i) {
        if (i > coins.size() or amount < 0) return 0;
        if (dp[amount][i] != -1) return dp[amount][i];
        if (amount == 0) return 1;
        int count = 0;
        for (int j = i; j < coins.size(); j++) {
            count+=util(amount-coins[j], coins, j);
        }
        return dp[amount][i] = count;
    }
};
