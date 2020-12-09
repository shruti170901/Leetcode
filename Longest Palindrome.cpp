// https://leetcode.com/problems/longest-palindrome/

class Solution {
public:
    int longestPalindrome(string s) {
        map<char, int> m;
        int i, n=s.size(), ans=0, odd=0;
        for(i=0;i<n;i++) m[s[i]]++;
        for(auto it:m){
            ans+=2*(it.second/2);
            if(it.second&1) odd=1;
        }
        return ans+odd;
    }
};