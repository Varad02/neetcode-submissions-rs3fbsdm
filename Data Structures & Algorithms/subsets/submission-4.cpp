class Solution {
public:
    vector<vector<int>> ans;
    vector<vector<int>> subsets(vector<int>& nums) {
        util(nums, -1, vector<int>());
        return ans;
    }
    void util(vector<int>& nums, int i, vector<int> curr) {
        if (i == nums.size()) return;
        ans.push_back(curr);
        for (int j = i+1; j < nums.size(); j++) {
            curr.push_back(nums[j]);
            util(nums, j, curr);
            curr.pop_back();
        }
    }
};
