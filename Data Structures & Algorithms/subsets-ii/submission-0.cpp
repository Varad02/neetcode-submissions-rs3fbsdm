class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> curr;
        res.push_back(curr);
        sort(nums.begin(), nums.end());
        util(nums, 0, curr);
        return res;
    }

    void util(vector<int>& nums, int start, vector<int> curr) {
        for (int i = start; i < nums.size(); i++) {
            if (i > start && nums[i] == nums[i-1]) continue;
            curr.push_back(nums[i]);
            res.push_back(curr);
            util(nums, i+1, curr);
            curr.pop_back();
        }
    }
};
