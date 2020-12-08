// https://leetcode.com/problems/word-break/

class Solution {
public:
    vector<int> dp;
    bool check(string &s, int idx, set<string>& dict){
        if(idx==s.size()) return true;
        if(dp[idx]!=-1) return dp[idx];
        string temp="";
        for(int i=idx;i<s.size();i++){
            temp.push_back(s[i]);
            if(dict.find(temp)!=dict.end() && check(s, i+1, dict)) {dp[idx]=1; return true;}
        }
        dp[idx]=0;
        return false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        set<string> dict(wordDict.begin(), wordDict.end());
        dp.resize(s.size(), -1);
        return check(s, 0, dict);
    }
};