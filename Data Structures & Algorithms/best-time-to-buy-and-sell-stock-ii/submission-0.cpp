class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minPrice = prices[0];
        int ans = 0;
        for (int i = 1; i < prices.size(); i++) {
            if (minPrice > prices[i]) {
                minPrice = prices[i];
                continue;
            }
            else{
                ans += prices[i] - minPrice;
                minPrice = prices[i];
            }
        }
        return ans;
    }
};