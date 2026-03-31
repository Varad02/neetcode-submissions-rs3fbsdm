class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& prerequisites) {
        vector<vector<int>>m(n);
        vector<int> freq(n);
        for (int i = 0; i < prerequisites.size(); i++) {
            freq[prerequisites[i][0]]++;
            m[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }
        queue<int> q;
        for (int i = 0; i < n; i++) {
            if (freq[i] == 0) {
                q.push(i);
            }
        }
        vector<int> res;
        while (!q.empty()) {
            int top = q.front();
            q.pop();
            res.push_back(top);
            for (auto i : m[top]) {
                freq[i]--;
                if (!freq[i])
                    q.push(i);
            }
        }
        if (res.size() != n)
            return {};
        return res;
    }
};
