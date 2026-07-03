class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int maxV = *max_element(nums.begin(), nums.end());
        int minV = *min_element(nums.begin(), nums.end());

        vector<int> count(maxV-minV+1, 0);

        for (auto n: nums) count[n-minV]++;

        for (int i = count.size()-1; i >= 0; i--) {
            k -= count[i];
            if (k <= 0) return i+minV;
        }

        return 0;
    }
};
