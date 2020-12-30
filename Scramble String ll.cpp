class Solution {
public:
    unordered_map<string,int> dp;
    
    bool solve(string a,string b){
        if(a.compare(b)==0)
            return 1;
        string key= a+' '+b;
        
        if(dp.find(key)!=dp.end())
            return dp[key];
        int n=a.length();
        
        
        for(int k=1;k<=n-1;k++){
            if((solve(a.substr(0,k),b.substr(0,k))==1&&solve(a.substr(k,n-k),b.substr(k,n-k))==1)||(solve(a.substr(0,k),b.substr(n-k,k))==1&&solve(a.substr(k,n-k),b.substr(0,n-k))==1)==1){
                return  dp[key]=1;
        
            }
        }
        return dp[key]=0;
    }
    bool isScramble(string s1, string s2) {
        if(s1.length()!=s2.length())
             return 0;
        if(s1.length()==s2.length()&&s1.length()==0)
             return 1;
        
        return solve(s1,s2);
        dp.clear();
    }
};
