class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        int n = nums.size();
        long long total = 0;
        for (int x : nums)
            total += x;
        int target = total % p;
        if (target == 0)
            return 0;

        unordered_map<int, int> last{{0, -1}};
        int cur = 0, ans = n;
        for (int i = 0; i < n; i++) {
            cur = (cur + nums[i]) % p;
            int need = ((cur - target) % p + p) % p;
            if (last.count(need))
                ans = min(ans, i - last[need]);
            last[cur] = i;
        }
        return ans == n ? -1 : ans;
    }
};