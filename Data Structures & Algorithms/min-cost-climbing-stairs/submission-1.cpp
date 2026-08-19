class Solution {
   public:
    vector<int> dp;
    int minCostClimbingStairs(vector<int>& cost) {
        dp.resize(cost.size() + 1, -1);
        return min(util(cost, 0), util(cost, 1));
    }
    int util(vector<int>& cost, int i) {
        if (i >= cost.size()) return 0;
        if (dp[i] != -1) return dp[i];
        return dp[i] = cost[i] + min(util(cost, i + 2), util(cost, i + 1));
    }
};
