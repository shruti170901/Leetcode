// https://leetcode.com/problems/minimum-add-to-make-parentheses-valid/

class Solution {
public:
    int minAddToMakeValid(string S) {
        int i, ans=0;
        stack<char> stk;
        for(i=0;i<S.size();i++){
            if(S[i]=='(') stk.push('(');
            else if(!stk.empty()) stk.pop();
            else ans++;
        }
        return ans+stk.size();
    }
};