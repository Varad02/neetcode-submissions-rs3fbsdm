class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char, pair<int, int>> m;
        for (int i = 0; i < s.length(); i++) {
            if (m.find(s[i])==m.end()) {
                m[s[i]] = {i, i};
            } else {
                m[s[i]].second = i;
            }
        }
        vector<pair<int, int>> intervals;
        for (auto i: m) {
            intervals.push_back(i.second);
        }
        return mergeIntervals(intervals);
    }

    vector<int> mergeIntervals(vector<pair<int,int>>& intervals) {
    if (intervals.empty()) return {};

    sort(intervals.begin(), intervals.end()); 
    // sorts by first, then second automatically for pair

    vector<pair<int,int>> merged;
    merged.push_back(intervals[0]);

    for (int i = 1; i < intervals.size(); ++i) {
        auto& last = merged.back();
        auto& curr = intervals[i];

        if (curr.first <= last.second) {
            // overlapping
            last.second = max(last.second, curr.second);
        } else {
            merged.push_back(curr);
        }
    }
    vector<int> res;
    for (auto i: merged) {
        res.push_back(i.second-i.first+1);
    }
    return res;
}

};
