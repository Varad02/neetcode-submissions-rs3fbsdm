class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int, int>> carspeed(position.size());
        for (int i = 0; i < position.size(); i++) {
            carspeed[i].first = position[i];
            carspeed[i].second = speed[i];
        }
        sort(carspeed.begin(), carspeed.end());

        double taken = -1;
        int ans = 1;
        for (int i = position.size() - 1; i >= 0; i--) {
            double time =
                (double)(target - carspeed[i].first) / carspeed[i].second;
            if (taken == -1)
                taken = time;

            if (time > taken) {
                ans++;
                taken = time;
            }
        }
        return ans;
    }
};