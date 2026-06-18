class Solution {
public:
    vector<vector<int>> dp;

    int util(vector<int>& prices, int i, int canBuy) {
        if (i >= prices.size())
            return 0;
        if (dp[i][canBuy] != -1)
            return dp[i][canBuy];

        if (canBuy) {
            dp[i][canBuy] = max(util(prices, i + 1, 1),
                                -prices[i] + util(prices, i + 1, 0));
        } else {
            dp[i][canBuy] = max(util(prices, i + 1, 0),
                                +prices[i] + util(prices, i + 2, 1));
        }
        return dp[i][canBuy];
    }

    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        dp.assign(n + 2, vector<int>(2, -1));
        return util(prices, 0, 1);
    }
};