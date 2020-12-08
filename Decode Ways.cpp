// https://leetcode.com/problems/decode-ways/

class Solution {
public:
    vector<long long> memo;
    long long num(string &s, long long idx){
        if(idx==s.size()) return 1;
        if(memo[idx]>=0) return memo[idx];
        long long temp=0, t1=0;
        if(s[idx]=='0'){
            memo[idx]=0;
            return 0;
        }
        temp=num(s, idx+1);
        if(idx<s.size()-1){
            long long x=(s[idx]-'0')*10+s[idx+1]-'0';
            if(x>=10 && x<=26) temp+=num(s, idx+2);
            //cout<<temp<<endl;
        }
        memo[idx]=temp;
        return temp;
        
    }
    int numDecodings(string s) {
        memo.resize(s.size(), -1);
        long long ans=max(num(s, 0), 0ll);
        
        for(auto it:memo) cout<<it<<" ";cout<<endl;
        return ans;
    }
};