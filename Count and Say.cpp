// https://leetcode.com/problems/count-and-say/

class Solution {
public:
    string countAndSay(int n) {
        if(n==1) return "1";
        int i, j, sz;
        string s=countAndSay(n-1), ans="";
        sz=s.size();
        i=0; j=0;
        while(i<sz && j<sz){
            j=i;
            while(j<sz && s[j]==s[i]) j++;
            ans+=char(j-i+'0');
            ans+=s[i];
            i=j;
        }
        return ans;
    }
};