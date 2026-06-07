class Solution {
public:
    int characterReplacement(string s, int k) {
        int i = 0, j = 0, maxFreq = 0, ans = 0;
        int freq[26] = {0};
        while (i < s.length() and j < s.length()) {
            freq[s[j] - 'A']++;
            maxFreq = max(maxFreq, freq[s[j] - 'A']);
            if (j-i+1-maxFreq > k) {
                freq[s[i] - 'A']--;
                i++;
            }
            ans = max(ans, j-i+1);
            j++;
        }
        return ans;
    }
};