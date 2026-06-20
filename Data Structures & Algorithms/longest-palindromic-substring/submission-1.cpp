class Solution {
   public:
    string longestPalindrome(string s) {
        int ansLen = 0;
        string ans = "";
        for (int i = 0; i < s.length(); i++) {
            string temp1 = util(i, i + 1, s);
            string temp2 = util(i - 1, i + 1, s);
            if (ansLen < temp1.length()) {
                ans = temp1;
                ansLen = temp1.length();
            }
            if (ansLen < temp2.length()) {
                ans = temp2;
                ansLen = temp2.length();
            }
        }
        return ans;
    }

    string util(int i, int j, string& s) {
        while (i >= 0 and j < s.length() and s[i] == s[j]) {
            i--;
            j++;
        }
        return s.substr(i + 1, j - i - 1);
    }
};
