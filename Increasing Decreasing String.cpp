// https://leetcode.com/problems/increasing-decreasing-string/

class Solution {
public:
    string sortString(string s) {
        string ans="";
        int i, arr[26]={0}, n=s.size();
        for(i=0;i<n;i++) arr[s[i]-'a']++;
        i=0;
        while(ans.size()<n){
            i=0;
            while(i<26){
                if(arr[i]>0){
                    ans+=char(i+'a');
                    arr[i]--;
                }
                i++;
            }
            i--;
            while(i>=0){
                if(arr[i]>0){
                    ans+=char(i+'a');
                    arr[i]--;
                }
                i--;
            }
        }
        return ans;
    }
};