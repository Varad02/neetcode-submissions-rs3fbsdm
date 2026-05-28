class Solution {
public:
    vector<vector<int>> dp;
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        dp.assign(n+2, vector<int> (n+2, 0));
        nums.insert(nums.begin(), 1);
        nums.push_back(1);
        return util(1, n, nums);
    }

    int util(int l, int r, vector<int>& nums) {
        if (dp[l][r] != 0) return dp[l][r];
        int ans = 0;
        for (int i = l; i <= r; i++) {
            int curr = (nums[i] * nums[l-1] * nums[r+1]) + util(l, i-1, nums) + util(i+1, r, nums);
            ans = max(ans, curr);
        }
        return dp[l][r] = ans;
    }
};
