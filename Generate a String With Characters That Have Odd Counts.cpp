// https://leetcode.com/problems/generate-a-string-with-characters-that-have-odd-counts/

class Solution {
public:
    string generateTheString(int n) {
        string s="";
        if(n%2) for(int i=0;i<n;i++) s+="a";
        else{
            for(int i=0;i<n-1;i++) s+="a";
            s+="b";
        }
        return s;
    }
};