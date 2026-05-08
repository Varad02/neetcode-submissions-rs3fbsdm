class Solution {
public:

    vector<int> par;
    vector<int> rank;

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        par.resize(n+1);
        rank.assign(n+1, 1);
        for (int i = 0; i < n+1; i++) par[i] = i;
        for (auto i: edges) {
            if (!unionJoint(i[0], i[1])){
                return i;
            }
        }
    }

    int findParent(int a) {
        while (a!=par[a]) {
            par[a] = par[par[a]];
            a = par[a];
        }
        return a;
    }

    bool unionJoint(int a, int b) {
        int pA = findParent(a);
        int pB = findParent(b);

        if (pA == pB) return false;

        if (rank[pA] > rank[pB]) {
            par[pB] = pA;
            rank[pA] += rank[pB];
        } else {
            par[pA] = pB;
            rank[pB] += rank[pA];
        }
        return true;
    }
};
