class Solution {
public:
    vector<vector<int>> dp;

    bool isMatch(string s, string p) {
        dp.assign(s.length()+1, vector<int>(p.length()+1, -1));
        return util(s, p, 0, 0);
    }
    
    bool util(const string& s, const string& p, int i, int j) {
        if(dp[i][j] != -1) return dp[i][j];
        if (i == s.length()) {
            while (j < p.length()) {
                if (j + 1 < p.length() && p[j + 1] == '*') {
                    j += 2;
                } else {
                    return dp[i][j] = false;
                }
            }
            return dp[i][j] = true;
        }
        if (j == p.length()) {
            return dp[i][j] = false;
        }
        if (j + 1 < p.length() and p[j+1] == '*') {
            cout << p[j] << " ";
            if(p[j]=='.') {
                return dp[i][j] = util(s, p, i+1, j) or util(s, p, i, j+2);
            }
            else {
                bool flag = false;
                if (p[j] == s[i]) {
                    flag = flag or util(s, p, i+1, j);
                }
                return dp[i][j] = flag or util(s, p, i, j+2);
            }
        }
        else if (p[j] == '.' || p[j] == s[i]) {
            return dp[i][j] = util(s, p, i+1, j+1);
        }
        else {
            return dp[i][j] = false;
        }
    }
};