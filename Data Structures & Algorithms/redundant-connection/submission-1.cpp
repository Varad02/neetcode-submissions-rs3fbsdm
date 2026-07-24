class UnionFind {
public:
    vector<int> parent;
    UnionFind(int size) {
        parent.push_back(0);
        for (int i = 1; i <= size; i++)
            parent.push_back(i);
    }

    int findParent(int i) {
        if (i == parent[i])
            return i;
        return findParent(parent[i]);
    }

    void assignParent(int i, int j) {
        int parentI = findParent(i);
        int parentJ = findParent(j);
        parent[parentJ] = parentI;
    }
};

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        UnionFind unionFind(edges.size());
        vector<int> ans;
        for (auto i : edges) {
            if (unionFind.findParent(i[0]) != unionFind.findParent(i[1]))
                unionFind.assignParent(i[0], i[1]);
            else
                ans = i;
        }
        return ans;
    }
};