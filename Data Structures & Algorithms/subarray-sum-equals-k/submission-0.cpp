class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        int count = 0;
        for (int i = 0; i < nums.size(); i++) {
            m[i] = m[i-1]+nums[i];
        }
        for (int i = 0; i < nums.size(); i++) {
            for (int j = i; j < nums.size(); j++) {
                if (m[j]-m[i]+nums[i] == k) count++;
            }
        }
        return count;
    }
};