class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        priority_queue<pair<int, char>> pq;
        pq.push({a, 'a'});
        pq.push({b, 'b'});
        pq.push({c, 'c'});
        string res = "";
        while (true) {
            auto [l1, c1] = pq.top();
            if (l1 == 0)
                break;
            pq.pop();
            auto [l2, c2] = pq.top();
            pq.pop();
            if (l1 >= 2 && l1 > l2) {
                res += c1;
                res += c1;
                l1 -= 2;
            } else {
                res += c1;
                l1 -= 1;
            }
            if (l2 >= 1) {
                res += c2;
                l2 -= 1;
            } else {
                break;
            }
            pq.push({l2, c2});
            pq.push({l1, c1});
        }
        return res;
    }
};