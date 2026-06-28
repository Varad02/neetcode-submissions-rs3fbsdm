class Solution {
   public:
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();
        int s = word.size();
        if (s > m * n) return false;
        unordered_map<char, int> word_freq;
        for (int i = 0; i < s; i++) word_freq[word[i]]++;
        if (word_freq[word[0]] > word_freq[word[s - 1]]) reverse(word.begin(), word.end());

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (check(board, word, 0, i, j)) return true;
            }
        }
        return false;
    }
    bool check(vector<vector<char>>& board, string& word, int p, int i, int j) {
        if (p == word.size()) return true;

        if (i < 0 || i >= board.size()) return false;
        if (j < 0 || j >= board[0].size()) return false;
        if (word[p] != board[i][j]) return false;
        board[i][j] = '#';
        bool found = (check(board, word, p + 1, i - 1, j) || check(board, word, p + 1, i + 1, j) ||
                      check(board, word, p + 1, i, j - 1) || check(board, word, p + 1, i, j + 1));
        board[i][j] = word[p];
        return found;
    }
};