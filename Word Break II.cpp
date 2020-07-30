class Solution {
public:
    int n;
    vector<vector<string>> word_map;
    vector<vector<string>> dp;
    vector<bool> visited;
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        n = s.length();
        word_map = vector<vector<string>> (n);
        dp = vector<vector<string>>(n);
        visited = vector<bool>(n, false);
        populate_word_map(s, wordDict);
        create_sentences(0);
        return dp[0];
    }
    void populate_word_map(const string& s, vector<string>& wordDict) {
        int pos, l;
        for (auto& word : wordDict) {
            pos = 0;
            l = word.length();
            while ((pos = s.find(word, pos)) != string::npos) {
                word_map[pos].push_back(word);
                pos ++;
            }
        }
    }
    void create_sentences(int pos) {
        for (auto& word : word_map[pos]) {
            int new_pos = pos + word.length();
            if (new_pos == n) dp[pos].push_back(word);
            else {
                if (!visited[new_pos])
                    create_sentences(new_pos);
                for (auto& sentence : dp[new_pos])
                    dp[pos].push_back(word + " " + sentence);
            }
        }
        visited[pos] = true;
    }
};
