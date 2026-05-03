class Solution {
public:
    
    int util (vector<int>& nums, int target, int i, unordered_map<long long, int>& dp) {
        auto key = [](int a, int b) { return (long long)a << 32 | (unsigned)b; };
        if (i == nums.size() and target == 0) return 1;
        if (i == nums.size()) return 0;
        if (dp.find(key(i, target)) != dp.end()) return dp[key(i, target)];
        return dp[key(i, target)] = dp[key(i, target)]+(util(nums, target - nums[i], i+1, dp) + util(nums, target + nums[i], i+1, dp));
    }
    
    int findTargetSumWays(vector<int>& nums, int target) {
        unordered_map<long long, int> dp;
        return util(nums, target, 0, dp);
    }
};
