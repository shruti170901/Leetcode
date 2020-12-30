// Question
// Given alphanumeric string s. (Alphanumeric string is a string consisting
// of lowercase English letters and digits).
// You have to find a permutation of the string where no letter is followed by another letter and no digit is followed by another digit.
 // That is, no two adjacent characters have the same type.
// Return the reformatted string or return an empty string if it is impossible to reformat the string.
// link to the question:https://leetcode.com/problems/reformat-the-string/
// Example Input and Output
// Input: s = "covid2019"
// Output: "c2o0v1i9d"
 // Program
 class Solution {
public:
    string reformat(string s) {
        vector<char>v1;
        vector<char>v2;
        string ans="";
    for(int i=0;i<s.length();i++)
    {
        if(isalpha(s[i]))
            v1.push_back(s[i]);
            else
                v2.push_back(s[i]);
    }
      int c=v2.size()-v1.size();
            if(c==1 || c==0)
            {
                for(int i=0;i<v2.size();i++)
                    {
                    ans+=v2[i];
                    if(i<v1.size())
                        ans=ans+v1[i];
                }
                return ans;
            }
        else if(c==-1)
        {
            for(int i=0;i<v1.size();i++)
            {
                ans+=v1[i];
                if(i<v2.size())
                    ans=ans+v2[i];
            }
            return ans;
        }
        else
            return "";
    }
};
