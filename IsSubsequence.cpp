class Solution {
public:
    bool isSubsequence(string s, string t) {
        int n=s.length(),m=t.length();
        int found=0;
        int j=0;
        for(int i=0;i<n;i++){
            for(;j<m;j++){
                if(s[i]==t[j]){
                    found++;
                    j++;
                    break;
                }
            }
        }
        if(found==n)return true;
        else return false;
    }
};
