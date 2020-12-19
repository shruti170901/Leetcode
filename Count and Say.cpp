// https://leetcode.com/problems/count-and-say/

class Solution {
public:
     
    string fun(string x){
     string ans="";
        for(int i=0;i<x.length();){
           if(i!=x.length()-1&&x[i]==x[i+1]){
               int j=i;
               int cnt=1;
               while(j<x.length()&&x[j]==x[j+1]){
                   j++;
                   cnt++;
               }
               ans+=to_string(cnt)+x[i];
               i+=cnt;
           }
            else{
                ans+=to_string(1)+x[i];
                i++;
            }
        }
        return ans;
    }
    string countAndSay(int n) {
        if(n<0){
            return "";
        }
        if(n==1){
            return "1";
        }
        string s=to_string(1);
        string ans="";
        for(int i=2;i<=n;i++){
                ans= fun(s);
                s=ans;
        }
        return ans;
    }
};
