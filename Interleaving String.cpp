// https://leetcode.com/problems/interleaving-string/

class Solution {
public:
    vector<vector<vector<int>>> memo;
    int check(string &s1, int i, string &s2, int j, string &s3, int k){
        if(memo[i][j][k]!=-1) return memo[i][j][k];
        bool temp=false;
        if(k==s3.size()) temp = i==s1.size() && j==s2.size();
        else if(i<s1.size() && j<s2.size()){
            if(s1[i]==s3[k] && s2[j]==s3[k]) temp = check(s1, i+1, s2, j, s3, k+1) || check(s1, i, s2, j+1, s3, k+1);
            else if(s1[i]==s3[k]) temp = check(s1, i+1, s2, j, s3, k+1);
            else if(s2[j]==s3[k]) temp = check(s1, i, s2, j+1, s3, k+1);
            else temp = false;
        }
        else if(i==s1.size()){
            if(s2[j]==s3[k]) temp = check(s1, i, s2, j+1, s3, k+1);
            else temp = false;
        }
        else if(j==s2.size()){
            if(s1[i]==s3[k]) temp = check(s1, i+1, s2, j, s3, k+1);
            else temp = false;
        }
        if(temp) memo[i][j][k]=1;
        else memo[i][j][k]=0;
        return memo[i][j][k];
    }
    bool isInterleave(string s1, string s2, string s3) {
        memo.resize(s1.size()+1, vector<vector<int>>(s2.size()+1, vector<int>(s3.size()+1, -1)));
        return check(s1, 0, s2, 0, s3, 0);
    }
};