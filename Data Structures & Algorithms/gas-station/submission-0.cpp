class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        int tGas = 0, tCost = 0;
        for (int i = 0; i < n; i++) {
            tGas+=gas[i];
            tCost+=cost[i];
        }
        if(tGas<tCost) return -1;
        tGas = 0, tCost = 0;
        int res = 0;
        int t = 0;
        for (int i = 0; i < n; i++) {
            t+=gas[i]-cost[i];
            if (t<0) {
                t = 0;
                res = i+1;
            }
        }
        return res;
    }
};
