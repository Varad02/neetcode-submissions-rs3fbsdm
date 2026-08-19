class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) return false;
        vector<int> sChars(26, 0), tChars(26, 0);
        for (int i = 0; i < s.length(); i++) {
            sChars[s[i]-'a']++;
            tChars[t[i]-'a']++;
        }
        for (int i = 0; i < 26; i++) {
            if(sChars[i] != tChars[i]) return false;
        }
        return true;
    }
};
