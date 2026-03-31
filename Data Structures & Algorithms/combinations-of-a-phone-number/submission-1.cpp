class Solution {
public:
    vector<string> ans;
    unordered_map<char, string> m = {
            {'2', "abc"},
            {'3', "def"},
            {'4', "ghi"},
            {'5', "jkl"},
            {'6', "mno"},
            {'7', "pqrs"},
            {'8', "tuv"},
            {'9', "wxyz"}
        };
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};
        util(digits, 0, digits.size(), "");
        return ans;
    }

    void util (string digits, int i, int n, string a) {
        if (i==n) {
                ans.push_back(a);
        }
        for (auto s: m[digits[i]]) {
            util(digits, i+1, n, a+s);
        }
    }
};
