class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq;
        for (auto i: stones) pq.push(i);
        while (true) {
            if (pq.empty() or pq.size() == 1) break;
            int x = pq.top();
            pq.pop();
            int y = pq.top();
            pq.pop();
            if (x==y) continue;
            else {
                pq.push(x-y);
            }
        }
        if (pq.size() == 1) {
            return pq.top();
        }
        return 0;
    }
};
