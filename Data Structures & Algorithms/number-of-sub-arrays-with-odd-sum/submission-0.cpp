class Solution {
public:
    int numOfSubarrays(vector<int>& nums) {
        const int MOD = 1e9 + 7;
        int even = 1, odd = 0, sum = 0, ans = 0;
        for (int x : nums) {
            sum += x;
            if (sum % 2 == 0) {
                ans = (ans + odd) % MOD;
                even++;
            } else {
                ans = (ans + even) % MOD;
                odd++;
            }
        }
        return ans;
    }
};