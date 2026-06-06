class Solution {
public:
    vector<vector<int>> dp;
    bool isInterleave(string s1, string s2, string s3) {
        if (s1.length() + s2.length() != s3.length()) return false;
        if (s1.length() == 0 or s2.length() == 0) return s1==s3 or s2==s3;
        dp.assign(s1.length()+1, vector<int>(s2.length()+1, -1));
        return util(s1, s2, s3, 0, 0);
    }

    bool util(string s1, string s2, string s3, int i1, int i2) {
        if (i1+i2+2 == s3.length()) return true;
        if (dp[i1][i2] != -1) return dp[i1][i2];
        bool flag = false;
        if(i1 < s1.length() and s3[i1+i2] == s1[i1]) flag |= util(s1, s2, s3, i1+1, i2);
        if(i2 < s2.length() and s3[i1+i2] == s2[i2]) flag |= util(s1, s2, s3, i1, i2+1);
        return dp[i1][i2] = flag;
    }
};
