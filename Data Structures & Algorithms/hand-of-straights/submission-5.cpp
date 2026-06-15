class Solution {
   public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if (hand.size() % groupSize != 0) return false;
        map<int, int> m;
        for (int card : hand) m[card]++;

        for (auto& [val, freq] : m) {
            if (freq == 0) continue;
            int count = freq;
            for (int j = val + 1; j < val + groupSize; j++) {
                if (m[j] < count) return false;
                m[j] -= count;
            }
        }
        return true;
    }
};
