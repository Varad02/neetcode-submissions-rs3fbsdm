class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string> dead(deadends.begin(), deadends.end());
        if (dead.count("0000")) return -1;
        if (target == "0000") return 0;
        unordered_set<string> visited{"0000"};
        queue<string> q;
        q.push("0000");
        int turns = 0;
        while (!q.empty()) {
            int sz = q.size();
            turns++;
            while (sz--) {
                string cur = q.front(); q.pop();
                for (int i = 0; i < 4; i++) {
                    for (int d : {1, -1}) { 
                        string next = cur;
                        next[i] = '0' + ((next[i] - '0' + d + 10) % 10);
                        if (dead.count(next) || visited.count(next)) continue;
                        if (next == target) return turns;
                        visited.insert(next);
                        q.push(next);
                    }
                }
            }
        }
        return -1;
    }

};