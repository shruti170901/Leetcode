// https://leetcode.com/problems/di-string-match/

class Solution {
public:
    vector<int> diStringMatch(string S) {
        int i, l, r, n=S.size();
        vector<int> v(n+1);
        l=0; r=n;
        for(i=0;i<n;i++){
            if(S[i]=='D') v[i]=r--;
            else v[i]=l++;
        }
        v[i]=r;
        return v;
    }
};