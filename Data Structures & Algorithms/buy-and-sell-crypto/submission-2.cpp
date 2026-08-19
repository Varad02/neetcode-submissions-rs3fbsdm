class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int answer = 0, minValue = prices[0];
        for (int i = 1; i < prices.size(); i++) {
            minValue = min(minValue, prices[i]);
            answer = max(answer, prices[i]-minValue);
        }
        return answer;
    }
};