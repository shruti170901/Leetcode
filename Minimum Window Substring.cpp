// https://leetcode.com/problems/minimum-window-substring/

class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> ma, mb;
        int i=0, j=0, n=s.size(), form=0, m=t.size(), idx=-1, len=INT_MAX;
        string ans="";
        if(n==0 || m==0) return "";
        for(i=0;i<m;i++) ma[t[i]]++;
        i=0;
        while(i<n && j<n){
            while(j<n && form<ma.size()){
                if(ma.find(s[j])!=ma.end()){
                    mb[s[j]]++;
                    if(mb[s[j]]==ma[s[j]]) form++;
                }
                j++;
            }
            //cout<<i<<" "<<j<<" "<<form<<" "<<ma.size()<<endl;
            if(j==n && form<ma.size()) break;
            //else if(j==n && form==ma.size()){idx=i;len=j-i;break;}
            //cout<<i<<" "<<j<<'\n';
            while(i<j && form==ma.size()){
                if(ma.find(s[i])!=ma.end()){
                    mb[s[i]]--;
                    if(mb[s[i]]<ma[s[i]]) form--;
                }
                i++;
                //cout<<i<<"??\n";
            }
            if(j-i+1<len){
                len=j-i+1;
                idx=i-1;
            }
        }
        if(idx==-1) return "";
        return s.substr(idx, len);
    }
};