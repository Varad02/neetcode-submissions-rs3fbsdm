class DisJointSet {
public:
    vector<int> parent, rank;
    DisJointSet(int n) {
        for (int i = 0; i < n; i++) {
            parent.push_back(i);
            rank.push_back(0);
        }
    }

    int findParent(int i) {
        if (parent[i] == i)
            return i;
        return parent[i] = findParent(parent[i]);
    }

    void mergeSets(int i, int j) {
        int parentI = findParent(i);
        int parentJ = findParent(j);
        if (parentI == parentJ)
            return;
        if (rank[parentI] < rank[parentJ])
            swap(parentI, parentJ);
        parent[parentJ] = parentI;
        if (rank[parentI] == rank[parentJ])
            rank[parentI]++;
    }
};

class Solution {
public:
    // skip = index to exclude, force = index to include first (-1 = none)
    int getMST(int n, vector<vector<int>>& edges, int skip, int force) {
        DisJointSet disJointSet(n);
        int mst = 0, used = 0;
        if (force != -1) {
            disJointSet.mergeSets(edges[force][0], edges[force][1]);
            mst += edges[force][2];
            used++;
        }
        for (int i = 0; i < edges.size(); i++) {
            if (i == skip)
                continue;
            auto& edge = edges[i];
            if (disJointSet.findParent(edge[0]) ==
                disJointSet.findParent(edge[1]))
                continue;
            disJointSet.mergeSets(edge[0], edge[1]);
            mst += edge[2];
            used++;
        }
        return used == n - 1 ? mst : INT_MAX;
    }

    vector<vector<int>>
    findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges) {
        int m = edges.size();
        for (int i = 0; i < m; i++)
            edges[i].push_back(i);

        sort(edges.begin(), edges.end(),
             [](const vector<int>& a, const vector<int>& b) {
                 return a[2] < b[2];
             });

        int baseMST = getMST(n, edges, -1, -1);
        vector<vector<int>> ans(2);
        for (int i = 0; i < m; i++) {
            if (getMST(n, edges, i, -1) > baseMST)
                ans[0].push_back(edges[i][3]);
            else if (getMST(n, edges, -1, i) == baseMST)
                ans[1].push_back(edges[i][3]);
        }
        return ans;
    }
};