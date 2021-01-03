class Solution {
public:
    vector<int> partitionLabels(string S) {
        int mp[26];
        for(int i=0;i<S.length();i++)
        {
            mp[S[i]-'a']=i;
        }
        // for(auto i:mp)
        //     cout<<i.first<<" "<<i.second<<"\n";
        int i=0;
        vector<int>ans;
        while(i<S.length())
        {
            int x=mp[S[i]-'a'];
            int j=i;
            while(j!=x)
            {
                x=max(x,mp[S[j]-'a']);
                j++;
            }
            ans.push_back(j-i+1);
            i=j+1;
        }
        return ans;
    }
};