class Solution {
public:
    vector<int> dp;
    int tribonacci(int n) {
        dp.assign(n+1, 0);
        return util(n);
    }

    int util (int n) {
        if (n<=0) return 0;
        if (n==1 or n==2) return 1;
        if (dp[n]!=0) return dp[n];
        return dp[n] = util(n-1) + util(n-2) + util(n-3);
    }
};