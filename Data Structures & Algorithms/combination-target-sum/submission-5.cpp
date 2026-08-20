class Solution {
public:
    vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int> > res;
        vector<int> combination;
        combinationSum(candidates, target, res, combination, 0);
        return res;
    }
private:
    void combinationSum(vector<int> &candidates, int target, vector<vector<int> > &res, vector<int> &combination, int i) {
        if (target < 0) return;
        if (!target) {
            res.push_back(combination);
            return;
        }
        for (; i != candidates.size() && target >= candidates[i]; i++) {
            combination.push_back(candidates[i]);
            combinationSum(candidates, target - candidates[i], res, combination, i);
            combination.pop_back();
        }
    }
};