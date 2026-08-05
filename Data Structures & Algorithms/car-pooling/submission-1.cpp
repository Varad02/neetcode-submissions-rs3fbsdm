class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq1;
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq2;
        for (auto trip : trips) {
            pq1.push({trip[1], trip[2], trip[0]});
        }
        int curr = 0;
        while (!pq1.empty()) {
            vector<int> trip = pq1.top();
            pq1.pop();
            curr = trip[0];
            while (!pq2.empty() and pq2.top()[0] <= curr) {
                capacity += pq2.top()[2];
                pq2.pop();
            }
            pq2.push({trip[1], trip[0], trip[2]});
            capacity -= trip[2];
            if (capacity < 0)
                    return false;
        }
        return true;
    }
};