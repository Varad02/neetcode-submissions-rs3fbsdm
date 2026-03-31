class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& prerequisites) {
        if (prerequisites.size() == 0) {
            vector<int> arr(n);
            iota(arr.begin(), arr.end(), 0);
            return arr;
        }
        unordered_map<int, vector<int>> m;
        unordered_map<int, vector<int>> m2;
        vector<int> non(n, 0);
        for (auto i : prerequisites) {
            m[i[1]].push_back(i[0]);
            m2[i[0]].push_back(i[1]);
            non[i[0]] = 1;
        }
        queue<int> q;
        for (int i = 0; i < n; i++) {
            if (non[i] == 0){
                cout << i << " ";
                q.push(i);
            }
        }
        vector<int> visited(n, 0), res;
        while (!q.empty()) {
            int top = q.front();
            q.pop();
            res.push_back(top);
            if(res.size() == n) break;
            if (visited[top] != 0)
                return {};
            visited[top] = 1;
            vector<int> pre = m[top];
            for (auto i : pre) {
                bool f = true;
                for (auto j: m2[i]) {
                    if (visited[j]!=1) f = false;
                }
                if (f)
                q.push(i);
            }
        }
        if (res.size()!=n) return {};
        return res;
    }
};
