// https://leetcode.com/problems/subdomain-visit-count/

class Solution {
public:
    vector<string> subdomainVisits(vector<string>& cp) {
        map<string, int> m;
        vector<string> v;
        int i, j, n=cp.size(), num, sz;
        for(i=0;i<n;i++){
            num=0; sz=cp[i].size();
            for(j=0;cp[i][j]!=' ';j++) num=10*num+cp[i][j]-'0';
            cp[i][j]='.';
            while(j<sz){
                if(cp[i][j]=='.') m[cp[i].substr(j+1, sz)]+=num;
                j++;
            }
        }
        for(auto it:m){
            v.push_back(to_string(it.second)+" "+it.first);
        }
        return v;
    }
};