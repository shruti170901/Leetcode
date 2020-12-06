class Solution {
public:
    string convert(string s, int num) {
        int i, j, n=s.size(), flag;
        if(num==1) return s;
        string ans="";
        for(i=0;i<num;i++){
            j=i; flag=0;
            if(i==num-1) flag=1;
            while(j<n){
                ans+=s[j];
                if(flag==0) j+=2*(num-i)-2;
                else j+=2*i;
                if(i>0 && i<num-1) flag^=1;
            }
        }
        return ans;
    }
};