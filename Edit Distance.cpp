// https://leetcode.com/problems/edit-distance/

class Solution {
public:
    int rec(string &w1, string &w2, int i, int j, vector<vector<int>>& memo){
        if(i==w1.size() || j==w2.size()) return w1.size()-i+w2.size()-j;
        if(memo[i][j]!=-1) return memo[i][j];
        int m1, m2, m3;
        if(w1[i]==w2[j]) return rec(w1, w2, i+1, j+1, memo);
        m1=rec(w1, w2, i, j+1, memo); //insert
        m2=rec(w1, w2, i+1, j, memo); //delete
        m3=rec(w1, w2, i+1, j+1, memo);
        memo[i][j]=1+min(min(m1, m2), m3);
        return 1+min(min(m1, m2), m3);
    }
    int minDistance(string word1, string word2) {
        vector<vector<int>> memo(word1.size(), vector<int>(word2.size(), -1));
        return rec(word1, word2, 0, 0, memo);
    }
};