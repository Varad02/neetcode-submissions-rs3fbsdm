class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& e, vector<double>& v, vector<vector<string>>& queries) {
        int n = e.size();
        unordered_map<string, vector<pair<string, double>>> graph;
        for (int i = 0; i < n; i++) {
            graph[e[i][1]].push_back({e[i][0], 1.0/v[i]});
            graph[e[i][0]].push_back({e[i][1], v[i]});
        }
        vector<double> ans;
        for (auto query: queries) {
            if (graph.find(query[0]) == graph.end() or graph.find(query[1]) == graph.end()) {
                ans.push_back(-1);
                continue;
            }
            if (query[0] == query[1]) {
                ans.push_back(1);
                continue;
            }
            queue<pair<string, double>> q;
            q.push({query[0], 1.0});
            unordered_set<string> vis;
            bool flag = false;
            while (!q.empty()) {
                auto [node, val] = q.front(); q.pop();
                vis.insert(node);
                for (auto i: graph[node]) {
                    if (vis.count(i.first) != 0) continue;
                    double newVal = val * i.second;
                    if (i.first == query[1]) {
                        ans.push_back(newVal);
                        flag = true;
                        break;
                    }
                    q.push({i.first, newVal});
                }
                if (flag) break;
            }
            if (!flag) ans.push_back(-1);
        }
        return ans;
    }
};