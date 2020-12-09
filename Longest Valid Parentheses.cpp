// https://leetcode.com/problems/longest-valid-parentheses/

class Solution {
public:
    int longestValidParentheses(string s) {
        int mx=0, dp[100000]={0};
        for(int i=0;i<s.size();i++){
            if(s[i]==')'){
                if(i>0 && s[i-1]=='('){
                    if(i>1) dp[i]=dp[i-2]+2;
                    else dp[i]=2;
                }
                else{
                    if(i>0 && i-dp[i-1]>0 && s[i-dp[i-1]-1]=='('){
                        if(i-dp[i-1]>1) dp[i]=dp[i-1]+dp[i-dp[i-1]-2]+2;
                        else dp[i]=dp[i-1]+2;
                    }
                }
            }
            mx=max(mx, dp[i]);
        }
        //for(int i=0;i<s.size();i++) cout<<dp[i]<<" ";
        return mx;
    }
};