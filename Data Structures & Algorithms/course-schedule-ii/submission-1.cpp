class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>> m;
        vector<int> freq(n, 0);
        for (auto i : prerequisites) {
            m[i[1]].push_back(i[0]);
            freq[i[0]]++;
        }
        queue<int> q;
        for (int i = 0; i < n; i++) {
            if (freq[i] == 0){
                q.push(i);
            }
        }
        vector<int> res;
        while (!q.empty()) {
            int top = q.front();
            q.pop();
            res.push_back(top);
            vector<int> pre = m[top];
            for (auto i : pre) {
                freq[i]--;
                if(!freq[i])
                q.push(i);
            }
        }
        if (res.size()!=n) return {};
        return res;
    }
};
