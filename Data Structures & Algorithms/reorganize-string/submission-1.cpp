class Solution {
public:
    string reorganizeString(string s) {
        unordered_map<char, int> m;
        for (auto ch : s)
            m[ch]++;
        priority_queue<pair<int, char>> pq;
        int maxF = 0;
        for (auto i : m) {
            pq.push({i.second, i.first});
            maxF = max(maxF, i.second);
        }
        if (maxF > (s.length() + 1) / 2)
            return "";
        string ans = "";
        while (!pq.empty()) {
            auto [freq, ch] = pq.top();
            pq.pop();
            ans += ch;
            if (pq.empty())
                break;
            auto [freq2, ch2] = pq.top();
            pq.pop();
            ans += ch2;
            if (--freq != 0)
                pq.push({freq, ch});
            if (--freq2 != 0)
                pq.push({freq2, ch2});
        }
        return ans;
    }
};