class Solution {
public:
    vector<string> commonChars(vector<string>& A) {
        int n = A.size();
        vector<vector<int>> freq(n, vector<int>(26, 0));
        vector<string> res;
        
        for (int i = 0; i < n; ++ i) {
            for (char c : A[i]) {
                freq[i][c - 'a'] ++;
            }
        }
        
        for (int j = 0; j < 26; ++ j) {
            int min_freq = INT_MAX;
            string cur_char(1, 'a'+j);
            for (int i = 0; i < n; ++ i) {
                min_freq = std::min(min_freq, freq[i][j]);
            }
            
            if (min_freq) {
                vector<string> tmp(min_freq, cur_char);
                res.insert(res.end(), tmp.begin(), tmp.end());
            }
        }
        return res;
    }
};
