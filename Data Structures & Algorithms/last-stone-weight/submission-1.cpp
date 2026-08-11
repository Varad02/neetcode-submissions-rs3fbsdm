class Solution {
   public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq;
        for (auto stone : stones) pq.push(stone);
        while (pq.size() > 1) {
            int stone1 = pq.top();
            pq.pop();
            int stone2 = pq.top();
            pq.pop();
            if (stone1 == stone2) continue;
            pq.push(abs(stone1 - stone2));
        }
        return pq.size() == 0 ? 0 : pq.top();
    }
};
