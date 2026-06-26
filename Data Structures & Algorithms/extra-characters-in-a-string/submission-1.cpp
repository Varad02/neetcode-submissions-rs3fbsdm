class Solution {
public:
    vector<int> dp;
    int util(string s, int i, vector<string>& dictionary) {
        if (i == s.length())
            return 0;
        if (dp[i] != -1)
            return dp[i];
        int ans = INT_MAX;
        for (auto word : dictionary) {
            int n = word.length();
            if (word == s.substr(i, n)) {
                cout << s.substr(i, n) << " ";
                ans = min(ans, util(s, i + n, dictionary));
            }
        }
        ans = min(ans, 1 + util(s, i + 1, dictionary));
        return dp[i] = ans;
    }

    int minExtraChar(string s, vector<string>& dictionary) {
        dp.assign(s.length() + 1, -1);
        return util(s, 0, dictionary);
    }
};