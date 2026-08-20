class Solution {
   public:
    vector<vector<int>> ans;
    vector<vector<int>> subsets(vector<int>& nums) {
        util(nums, 0, vector<int>());
        return ans;
    }
    void util(vector<int>& nums, int i, vector<int> curr) {
        if (i >= nums.size()) { ans.push_back(curr); return; }
        util(nums, i+1, curr);
        curr.push_back(nums[i]);
        util(nums, i+1, curr);
    }
};
