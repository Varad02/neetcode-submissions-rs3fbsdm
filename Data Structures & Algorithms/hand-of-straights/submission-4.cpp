class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if (hand.size()%groupSize != 0) return 0;
        unordered_map<int, int> m;
        for (auto i: hand) m[i]++;
        set<int> s(hand.begin(), hand.end());
        int n = 0;
        for (int i: s) {
            // if(n==s.size()-groupSize+1) break;
            int freq = m[i];
            m[i] = 0;
            for (int j = i+1; j < i+groupSize; j++) {
                if (m[j] < freq) return false;
                m[j]-=freq;
            }
            n++;
        }
        return true;
    }
};
