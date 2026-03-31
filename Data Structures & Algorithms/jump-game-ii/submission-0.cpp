class Solution {
public:
    vector<int> dp;
    int jump(vector<int>& nums) {
        dp.assign(nums.size(), -1);
        return util(nums, 0, nums.size(), 0)-1;
    }

    int util(vector<int>& nums, int i, int n, int jumps) {
        if(i>=n-1) return 1;
        if(nums[i]==0) return INT_MAX;
        if(dp[i]!=-1) return dp[i];
        int ans = INT_MAX;
        for (int j = i+1; j <= i+nums[i]; j++) {
            ans = min(util(nums, j, n, jumps+1), ans);
        }
        return dp[i] = 1+ans;
    }
};
