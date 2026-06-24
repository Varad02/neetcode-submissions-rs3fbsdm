class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1;
        int r = *max_element(piles.begin(), piles.end());
        int res;
        while (r>=l) {
            int k = (r+l) / 2;
            int time = 0;
            for (int p: piles) {
                time += ceil(static_cast<double>(p) / k);
            }
            if (time <= h) {
                r = k-1;
                res = k;
            } else {
                l = k+1;
            }
        }
        return res;
    }
};
