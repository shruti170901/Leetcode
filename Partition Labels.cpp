// https://leetcode.com/problems/partition-labels/

class Solution {
public:
    vector<int> partitionLabels(string S) {
        vector<int> v(26);
        int i, n=S.size();
        for(i=0;i<n;i++){
            v[S[i]-'a']=i;
        }
        int mx=-1, j;
        i=0; j=-1;
        vector<int> ans;
        while(i<n){
            if(mx==-1 || mx<v[S[i]-'a']){
                mx=v[S[i]-'a'];
            }
            if(i==mx){
                mx=-1;
                ans.push_back(i-j);
                j=i;
            }
            i++;
        }
        return ans;
    }
};