// https://leetcode.com/problems/find-and-replace-pattern/

class Solution {
public:
    string red(string& tbr){
        string ans="";
        char t='a'-1;
        int i, n=tbr.size();
        map<char, char> m;
        for(i=0;i<n;i++){
            if(m.find(tbr[i])==m.end()){
                t++;
                m[tbr[i]]=t;
                ans+=t;
            }
            else ans+=m[tbr[i]];
        }
        return ans;
    }
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        map<char, char> m;
        int i, j;
        string s, t;
        vector<string> ans;
        s=red(pattern);
        for(i=0;i<words.size();i++){
            t=red(words[i]);
            if(s==t) ans.push_back(words[i]);
        }
        return ans;
    }
};