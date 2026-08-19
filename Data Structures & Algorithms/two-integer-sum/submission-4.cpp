class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map <int, int> um;
        for (int i = 0; i < nums.size(); i++) {
            int num = nums[i];
            if (um.find(target-num) != um.end()) return {um[target-num], i};
            um[num] = i;
        }
        return vector<int>();
    }
};
