class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        unordered_map<int, vector<int>> m;
        for (auto i: edges) {
            m[i[0]].push_back(i[1]);
            m[i[1]].push_back(i[0]);
        }
        vector<bool> v(n, false);
        queue<pair<int, int>> q;
        q.push({0, -1});
        v[0] = true;
        while (!q.empty()) {
            auto [node, parent] = q.front();
            q.pop();
            for (auto i: m[node]) {
                if(i==parent) continue;
                if (v[i])
                return false;
                v[i] = true;
                q.push({i, node});
            }
        }
        for (auto i: v) if(!i) return false;
        return true;
    }
};
