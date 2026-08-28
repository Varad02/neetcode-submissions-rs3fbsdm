class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        int l = *max_element(nums.begin(), nums.end());
        int r = accumulate(nums.begin(), nums.end(), 0);
        int mid = 0;
        while (l < r) {
            mid = l + (r - l) / 2;
            if (util(mid, nums, k)) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        return r;
    }

    bool util(int mid, vector<int>& nums, int k) {
        int pieces = 1;
        int curr = 0;
        for (int x : nums) {
            if (curr + x > mid) {
                pieces++;
                curr = x;
            } else {
                curr += x;
            }
        }
        return pieces <= k;

    }
};