class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count = 1, candidate = nums[0];
        for (int i = 0; i < nums.size(); i++) {
            if (candidate == nums[i]) count++;
            else count--;
            if (count == 0) candidate = nums[i+1], i++;
        }
        return candidate;
    }
};