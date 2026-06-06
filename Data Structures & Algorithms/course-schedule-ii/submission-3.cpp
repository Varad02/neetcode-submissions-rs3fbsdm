class Solution {
   public:
    vector<int> findOrder(int n, vector<vector<int>>& pre) {
        vector<int> req(n);
        unordered_map<int, vector<int>> m;
        for (auto i: pre) {
            req[i[0]]++;
            m[i[1]].push_back(i[0]);
        }

        queue<int> q;
        for (int i = 0; i < n; i++) {
            if (req[i] == 0) {
                q.push(i);
            }
        }

        vector<int> res;
        while(!q.empty()) {
            int top = q.front();
            q.pop();
            res.push_back(top);
            for (auto i: m[top]) {
                req[i]--;
                if (req[i] == 0) q.push(i);
            }
        }
        if (res.size() == n) return res;
        return {};
    }
};
