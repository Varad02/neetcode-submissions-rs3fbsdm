class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& p) {
        vector<vector<int>> um(n);
        vector<int> t (n, 0);
        for (auto i: p) {
            um[i[1]].push_back(i[0]);
            t[i[0]]++;
        }
        queue<int> q;
        for (int i = 0; i <n; i++) {
            if(t[i] == 0) q.push(i);
        }
        vector<int> ans;
        while (!q.empty()) {
            int c = q.front(); q.pop();
            ans.push_back(c);
            for (int i: um[c]) {
                t[i]--;
                if (t[i] == 0) q.push(i);
            }
        }
        return ans.size() == n ? ans : vector<int>{};
    }
};