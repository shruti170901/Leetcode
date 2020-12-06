class Solution {
public:
    int exp(string &s, int l, int r){
        int i=l, j=r;
        while(i>=0 && j<s.size() && s[i]==s[j]) i--,j++;
        return j-i-1;
    }
    string longestPalindrome(string s) {
        int i, idx=0, len=1;
        for(i=0;i<s.size();i++){
            int l1=exp(s, i, i);
            int l2=exp(s, i, i+1);
            if(max(l1, l2)>len){
                len=max(l1, l2);
                idx=i-(len-1)/2;
            }
        }
        return s.substr(idx, len);
    }
};