class Solution {
public:

    void util(vector<vector<int>>& res, vector<int>& nums, vector<int>& curr, int i, int &n) {
        res.push_back(curr);
        for (int j = i; j < n; j++) {
            if (j > i and nums[j] == nums[j-1]) continue;
            curr.push_back(nums[j]);
            util(res, nums, curr, j+1, n);
            curr.pop_back();
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        vector<int> curr;
        int n = nums.size();
        util(res, nums, curr, 0, n);
        return res;
    }
};