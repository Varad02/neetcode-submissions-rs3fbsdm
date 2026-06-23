class Solution {
public:
    int maxCoins(vector<int>& nums) {
        nums.insert(nums.begin(), 1);
        nums.push_back(1);
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));

        for (int len = 2; len < n; len++) {
            for (int l = 0; l + len < n; l++) {
                int r = l + len;
                for (int i = l+1; i < r; i++) {
                    dp[l][r] = max(dp[l][r], nums[l]*nums[i]*nums[r] + dp[l][i] + dp[i][r]);
                }
            }
        }
        return dp[0][n-1];
    }
};