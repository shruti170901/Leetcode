// https://leetcode.com/problems/substring-with-concatenation-of-all-words/

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        unordered_map<string, int> cnt;
        vector<int> ans;
        if(s=="" || words.size()==0) return ans;
        for(string w:words) cnt[w]++;
        int i, j, n=s.size(), len=words[0].size(), w=words.size();
        for(i=0;i<n-len*w+1;i++){
            unordered_map<string, int> seen;
            for(j=0;j<w;j++){
                string temp=s.substr(i+j*len, len);
                if(cnt.find(temp)==cnt.end()) break;
                seen[temp]++;
                if(seen[temp]>cnt[temp]) break;
            }
            if(j==w) ans.push_back(i);
        }
        return ans;
    }
};