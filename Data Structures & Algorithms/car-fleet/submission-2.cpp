class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<vector<int>> c;
        int n = speed.size();
        for (int i = 0; i < n; i++) c.push_back({position[i], speed[i]});
        sort(c.begin(), c.end(), greater<>());
        priority_queue<float> pq;
        for (auto i: c) {
            float t = (float) (target-i[0])/i[1];
            if (pq.empty() or pq.top() < t) pq.push(t);
        }
        return pq.size();
    }
};
