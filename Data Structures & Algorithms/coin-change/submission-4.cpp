class Solution {
public:
    vector<int> memo;
    
    int dp(vector<int>& coins, int amount) {
        if (amount == 0) return 0;
        if (amount < 0) return -1;
        if (memo[amount] != -2) return memo[amount];
        
        int best = INT_MAX;
        for (int c : coins) {
            int sub = dp(coins, amount - c);
            if (sub != -1) best = min(best, sub + 1);
        }
        
        memo[amount] = (best == INT_MAX) ? -1 : best;
        return memo[amount];
    }
    
    int coinChange(vector<int>& coins, int amount) {
        memo.assign(amount + 1, -2);
        return dp(coins, amount);
    }
};