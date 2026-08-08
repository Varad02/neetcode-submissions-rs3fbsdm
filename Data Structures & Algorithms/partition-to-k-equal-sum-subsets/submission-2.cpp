class Solution {
   public:
    bool util(vector<int>& nums, vector<int>& sums, int i, int target) {
        if (i == nums.size()) return true;

        for (int j = 0; j < sums.size(); j++) {
            if (j > 0 && sums[j] == sums[j - 1]) continue;
            if (nums[i] > sums[j]) continue;

            sums[j] -= nums[i];
            if (util(nums, sums, i + 1, target)) return true;
            sums[j] += nums[i];

            if (sums[j] == target) break;
        }
        return false;
    }

    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int sum = 0;
        for (int x : nums) sum += x;
        if (sum % k) return false;

        sort(nums.begin(), nums.end(), greater<int>());
        int target = sum / k;
        if (nums[0] > target) return false;

        vector<int> sums(k, target);
        return util(nums, sums, 0, target);
    }
};