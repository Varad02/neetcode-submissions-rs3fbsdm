class Solution {
public:
    int trap(vector<int>& h) {
        int n = h.size();
        vector<int> maxFromI(n);
        maxFromI[n-1] = h[n-1];
        for (int i = n-2; i >= 0; i--)
            maxFromI[i] = max(h[i], maxFromI[i+1]);

        int ans = 0;
        int leftMax = 0;
        for (int i = 0; i < n; i++) {
            leftMax = max(leftMax, h[i]);
            int water = min(leftMax, maxFromI[i]) - h[i];
            if (water > 0) ans += water;
        }
        return ans;
    }
};