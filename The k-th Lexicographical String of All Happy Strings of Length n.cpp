// https://leetcode.com/problems/the-k-th-lexicographical-string-of-all-happy-strings-of-length-n/

class Solution {
public:
    string getHappyString(int n, int k) {
        n--;
        if(k>3*(1<<n)) return "";
        string s="";
        if(k<=(1<<n)) s+='a';
        else if(k<=2*(1<<n)) s+='b', k-=(1<<n);
        else s+='c', k-=(1<<(n+1));
        int i, t=n-1;
        char arr[]={'a', 'b', 'c'};
        for(i=0;i<n;i++){
            if(k<=(1<<t)){
                for(int j=0;j<3;j++){
                    if(arr[j]!=s[i]){
                        s+=arr[j];
                        break;
                    }
                }
            }
            else{
                for(int j=2;j>=0;j--){
                    if(arr[j]!=s[i]){
                        s+=arr[j];
                        break;
                    }
                }
                k-=(1<<t);
            }
            t--;
        }
        return s;
    }
};