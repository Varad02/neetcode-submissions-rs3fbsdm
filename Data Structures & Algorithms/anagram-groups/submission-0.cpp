class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> m;

        for (auto &str : strs) {
            vector<int> freq(26,0);
            for (auto c : str)
                freq[c-'a']++;

            string key;
            for (int x : freq) {
                key += to_string(x) + "#";
            }

            m[key].push_back(str);
        }

        vector<vector<string>> ans;
        for (auto &p : m) {
            ans.push_back(p.second);
        }

        return ans;
    }
};