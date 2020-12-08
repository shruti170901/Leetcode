// https://leetcode.com/problems/valid-palindrome/

class Solution {
public:
    bool isPalindrome(string s) {
        string u="", t="";
        int i;
        for(i=0;i<s.size();i++){
            if(isalnum(s[i])){
                u+=tolower(s[i]);
                t+=tolower(s[i]);
            }
        }
        cout<<u<<endl<<t<<endl;
        reverse(t.begin(), t.end());
        return u==t;
    }
};