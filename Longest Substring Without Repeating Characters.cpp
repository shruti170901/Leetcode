class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ans=0, len=0, i=0, j=0;
        set<char> se;
        while(i<s.size() && j<s.size()){
            while(j<s.size() && se.find(s[j])==se.end()){
                se.insert(s[j]);
                len++;
                j++;
                ans=max(ans, len);
            }
            if(j==s.size()) break;
            while(s[i]!=s[j]){
                se.erase(s[i]);
                len--;
                i++;
                ans=max(ans, len);
            }
            se.erase(s[i]);
            i++;
            len--;
            ans=max(ans, len);
        }
        return ans;
    }
};