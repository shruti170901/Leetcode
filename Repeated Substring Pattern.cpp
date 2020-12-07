// https://leetcode.com/problems/repeated-substring-pattern/

class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        vector<int> lps(s.size());
        int i=1, j, len=0;
        while(i<s.size()){
            if(s[i]==s[len]){
                len++;
                lps[i]=len;
                i++;
            }
            else{
                if(len==0){
                    lps[i]=0;
                    i++;
                }
                else len=lps[len-1];
            }
        }
        for(int it:lps) cout<<it<<" "; cout<<endl;
        j=lps.back();
        len=s.size();
        return len%(len-j)==0 && j!=0;
    }
};