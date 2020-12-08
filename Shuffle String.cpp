// https://leetcode.com/problems/shuffle-string/

class Solution {
public:
    string restoreString(string s, vector<int>& indices) {
        string ans(s.size(),'.');
        for(int i=0;i<s.size();i++){
            ans[indices[i]]=s[i];
        }
        return ans;
    }
};