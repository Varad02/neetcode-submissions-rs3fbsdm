class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> m;
        int ans = 0;
        int l = 0, r = 0;
        while (r < s.length()) {
            if (m.find(s[r]) == m.end()) {
                m[s[r]] = r;
            }
            else {
                if (m[s[r]] >= l) {
                    l = m[s[r]] + 1;
                }
                m[s[r]] = r;
            }
            r++;
            ans = max(ans, r-l);
        }
        return ans;
    }
};