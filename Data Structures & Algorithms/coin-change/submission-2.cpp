class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<vector<int>> memo(amount + 1, vector<int>(coins.size() + 1, -1));
        int ans = util(coins, amount, 0, memo);
        return ans == INT_MAX ? -1 : ans;
    }

    int util(vector<int>& coins, int amount, int i,
             vector<vector<int>>& memo) {
        if (amount < 0) return INT_MAX;
        if (amount == 0) return 0;
        if (i >= (int)coins.size()) return INT_MAX;

        if (memo[amount][i] != -1) return memo[amount][i];

        int ans = INT_MAX;

        int temp = util(coins, amount - coins[i], i, memo);
        if (temp != INT_MAX)
            ans = min(ans, 1 + temp);

        temp = util(coins, amount - coins[i], i + 1, memo);
        if (temp != INT_MAX)
            ans = min(ans, 1 + temp);
        temp = util(coins, amount, i + 1, memo);
        if (temp != INT_MAX)
            ans = min(ans, temp);

        return memo[amount][i] = ans;
    }
};