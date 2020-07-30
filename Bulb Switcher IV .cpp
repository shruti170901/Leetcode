class Solution {
public:
    int minFlips(string s) {
        int ans=0,n=s.length();
        if(n==1&&s=="0")return 0;
        if(n==1&&s=="1")return 1;
        char present=s[n-1];
        for(int i=n-2;i>=0;i--){
            if(s[i]!=present){
                ans++;
                present=s[i];
            }
        }
        if(present=='1')ans++;
        return ans;
    }
};
