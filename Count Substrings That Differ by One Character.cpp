// PROBLEM LINK: https://leetcode.com/problems/unique-paths/

class Solution {
        int d_p_1[105][105];
    int d_p_2[105][105];
public:
    int countSubstrings(string s, string t) {
        
        int n = s.size();
        int m = t.size();
        s = "$" + s + "$";
        t = "$" + t + "$";
        
        for(int i = 1; i < n; ++i) {
            for(int j = 1; j < m; ++j) {
                if(s[i] == t[j]) 
                    d_p_1[i][j] = d_p_1[i-1][j-1]+1;
                else 
                    d_p_1[i][j] = 0;
            }
        }
        
        for(int i = n; i >= 1; --i) {
            for(int j = m; j >= 1; --j) {
                if(s[i] == t[j]) 
                    d_p_2[i][j] = d_p_2[i+1][j+1]+1;
                else 
                    d_p_2[i][j] = 0;
            }
        }
        int r = 0;
        for(int i = 1; i <= n; ++i) {
            for(int j = 1; j <= m; ++j) {
                if(s[i] != t[j]) {
                    r += (d_p_1[i-1][j-1]+1) * (d_p_2[i+1][j+1]+1);
                }
            }
        }
        return r;
        
    }
};