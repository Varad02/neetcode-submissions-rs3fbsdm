class Solution {
public:
    bool differByOne(const std::string& a, const std::string& b) {
        if (a.size() != b.size())
            return false;
        int diff = 0;
        for (size_t i = 0; i < a.size(); ++i)
            if (a[i] != b[i] && ++diff > 1)
                return false;
        return diff == 1;
    }
    int ladderLength(string beginWord, string endWord,
                     vector<string>& wordList) {
        unordered_set<string> wordSet(wordList.begin(), wordList.end());
        if (wordSet.find(endWord) == wordSet.end()) {
            return 0;
        }
        unordered_map<string, vector<string>> graph;
        int n = wordList.size();
        wordList.push_back(beginWord);
        for (int i = 0; i < n+1; i++) {
            for (int j = i + 1; j < n+1; j++) {
                if (differByOne(wordList[i], wordList[j])) {
                    graph[wordList[i]].push_back(wordList[j]);
                    graph[wordList[j]].push_back(wordList[i]);
                }
            }
        }
        queue<pair<string, int>> q;
        unordered_map<string, bool> visited;
        q.push({beginWord, 0});
        visited[beginWord] = true;
        while (!q.empty()) {
            string word = q.front().first;
            int distance = q.front().second;
            q.pop();
            for (string i : graph[word]) {
                if (visited.find(i) != visited.end())
                    continue;
                int newDistance = distance + 1;
                if (i == endWord)
                    return newDistance+1;
                q.push({i, newDistance});
                visited[i] = true;
            }
        }
        return 0;
    }
};