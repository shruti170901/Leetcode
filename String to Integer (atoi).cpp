class Solution {
public:
    int myAtoi(string s) {
        long long i=0, n=s.size(), sgn=1, ans=0;
        while(i<n && s[i]==' ') i++;
        if(i==n) return 0;
        if(s[i]!='+' && s[i]!='-' && s[i]<'0' && s[i]>'9') return 0;
        if(s[i]=='+'){
            sgn=1;
            i++;
        }
        else if(s[i]=='-'){
            sgn=-1;
            i++;
        }
        for(;i<n && s[i]>='0' && s[i]<='9';i++){
            ans=10*ans+sgn*(s[i]-'0');
            if(ans>INT_MAX || ans<INT_MIN) break;
        }
        if(ans<=INT_MAX && ans>=INT_MIN) return ans;
        if(ans>INT_MAX) return INT_MAX;
        return INT_MIN;
    }
};