class Solution {
public:
    map<tuple<int,int,int,int,int>, int> dp;

    bool makesquare(vector<int>& matchsticks) {
        int sum = 0;
        for (auto i : matchsticks) sum += i;
        if (sum % 4 != 0) return false;
        return util(matchsticks, 0, 0, 0, 0, 0);
    }

    bool util(vector<int>& matchsticks, int s1, int s2, int s3, int s4, int i) {
        int target = 0;
        for (auto x : matchsticks) target += x;
        target /= 4;

        if (s1 > target or s2 > target or s3 > target or s4 > target)
            return false;

        if (i == matchsticks.size())
            return s1 == s2 and s1 == s3 and s1 == s4;

        auto key = make_tuple(s1, s2, s3, s4, i);
        if (dp.count(key)) return dp[key];

        bool result = util(matchsticks, s1 + matchsticks[i], s2, s3, s4, i + 1) or
                      util(matchsticks, s1, s2 + matchsticks[i], s3, s4, i + 1) or
                      util(matchsticks, s1, s2, s3 + matchsticks[i], s4, i + 1) or
                      util(matchsticks, s1, s2, s3, s4 + matchsticks[i], i + 1);

        return dp[key] = result ? 1 : 0;
    }
};