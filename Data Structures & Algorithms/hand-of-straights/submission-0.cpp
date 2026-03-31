class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n = hand.size();
        if (n%groupSize != 0) return 0;
        unordered_map<int, int> m;
        for (auto i: hand) {
            m[i]++;
        }
        sort (hand.begin(), hand.end());
        int count = 0;
        for (auto i: hand) {
            if(m[i]==0) continue;
            m[i]--;
            count++;
            for (int j = i+1; j < i+groupSize; j++) {
                if (m[j]==0) return false;
                m[j]--;
                count++;
            }
        }
        return count==n;
    }
};
