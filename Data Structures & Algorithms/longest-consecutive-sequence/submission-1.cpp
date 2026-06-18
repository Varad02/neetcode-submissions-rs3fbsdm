class Solution {
   public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, int> m;
        int res = 0;
        for (auto n : nums) {
            if (m[n] == 0) {
                m[n] = m[n - 1] + m[n + 1] + 1;
                m[n - m[n - 1]] = m[n];
                m[n + m[n + 1]] = m[n];
                res = max(res, m[n]);
            }
        }
        return res;
    }
};
