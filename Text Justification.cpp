// https://leetcode.com/problems/text-justification/

class Solution {
public:
    string just(vector<string>&v, int l, int r, int W){
        string ans="";
        int sum=0, i;
        for(i=l;i<r;i++) sum+=v[i].size();
        sum=W-sum;
        if(r-l==1){
            ans=v[l];
            for(i=0;i<sum;i++) ans+=" ";
            return ans;
        }
        string space;
        for(i=0;i<sum/(r-l-1);i++) space+=' ';
        sum%=(r-l-1);
        ans=v[l];
        for(i=l+1;i<r;i++){
            ans+=space;
            if(sum){
                ans+=" ";
                sum--;
            }
            ans+=v[i];
        }
        return ans;
    }
    vector<string> fullJustify(vector<string>& w, int maxWidth) {
        vector<string> ans;
        int i=0, j=0, n=w.size(), sz=0;
        while(i<n && j<n){
            sz=0;i=j;
            while(j<n && sz+w[j].size()+j-i<=maxWidth){
                sz+=w[j].size();
                j++;
            }
            cout<<i<<" "<<j<<endl;
            if(j<n){
                ans.push_back(just(w, i, j, maxWidth));
            }
            else{
                string temp="";
                for(;i<j-1;i++){
                    temp+=w[i];
                    temp+=" ";
                }
                temp+=w[i];
                while(temp.size()<maxWidth) temp+=" ";
                ans.push_back(temp);
            }
        }
        return ans;
    }
};