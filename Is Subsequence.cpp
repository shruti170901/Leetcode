class Solution {
public:
    bool isSubsequence(string s, string t) {
       unordered_map<char, vector<int>> m;
        for(int i=0;i<t.size();++i)
            m[t[i]].push_back(i); 
        
        int low = -1;
        for(int i=0;s[i]!='\0';++i)
        {
            int pos = upper_bound(m[s[i]].begin(),m[s[i]].end(),low)-m[s[i]].begin();
            if(pos==m[s[i]].size())
                return false;
            low = m[s[i]][pos];
        }
        return true;
    }
};
