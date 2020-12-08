// https://leetcode.com/problems/decrypt-string-from-alphabet-to-integer-mapping/

class Solution {
public:
    string freqAlphabets(string s) {
        s+="..";
        int i, n=s.size()-2, t;
        string ans="";
        for(i=0;i<n;i++){
            if(s[i+2]!='#') t=s[i]-'1';
            else{
                t=(s[i]-'0')*10+(s[i+1]-'0')-1;
                i+=2;
            }
            string temp(1, 'a'+t);
            ans+=temp;
        }
        return ans;
    }
};