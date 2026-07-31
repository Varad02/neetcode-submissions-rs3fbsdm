class Solution {
   public:
    string foreignDictionary(vector<string>& words) {
        unordered_map<char, vector<char>> adj;
        unordered_map<char, int> degree;
        for (const string& w : words)
            for (char ch : w) degree[ch];
        for (int i = 0; i < words.size() - 1; i++) {
            string word1 = words[i];
            string word2 = words[i + 1];
            if (word1 == word2) continue;
            int j = 0;
            while (word1[j] == word2[j] and j < word1.size() and j < word2.size()) {
                j++;
            }
            if (j == word2.size() and word1.size() > word2.size()) return "";
            if (word2[j]==word2[j-1]) continue;
            adj[word1[j]].push_back(word2[j]);
            degree[word2[j]]++;
        }
        queue<char> q;
        for (auto [i, j]: degree) 
            if(j==0)
                q.push(i);
        string ans = "";
        while (!q.empty()) {
            char c = q.front();
            q.pop();
            ans += c;
            for (char i : adj[c]) 
                if (--degree[i] == 0)
                    q.push(i);
        }
        return ans.size() == degree.size() ? ans : "";
    }
};