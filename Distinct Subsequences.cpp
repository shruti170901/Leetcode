// https://leetcode.com/problems/distinct-subsequences/

class Solution {
public:
    vector<vector<int>> memo;
    int find(string &s, string &t, int i1, int j1){
        if(memo[i1][j1]!=-1) return memo[i1][j1];
        if(j1==t.size()){
            memo[i1][j1]=1;
            return 1;
        }
        if(i1==s.size()){
            memo[i1][j1]=0;
            return 0;
        }
        int i, temp=0;
        for(i=i1;i<s.size();i++){
            if(s[i]==t[j1]){
                temp+=find(s, t, i+1, j1+1);
            }
        }
        memo[i1][j1]=temp;
        return temp;
    }
    int numDistinct(string s, string t) {
        memo.resize(s.size()+1, vector<int>(t.size()+1, -1));
        return find(s, t, 0, 0);
    }
};