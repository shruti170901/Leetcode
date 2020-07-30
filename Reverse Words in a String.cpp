class Solution {
public:
    string reverseWords(string s) {
        stringstream ssss(s);
        string res, str;
        while(ssss >> str) res = res.empty() ? str : str+' '+res;
        return res;
    }
};
