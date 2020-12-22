class Solution {
public:
    string toLowerCase(string str) 
    {
      int i;
      for (i=0;i<str.length();i++)
          str[i]=tolower(str[i]);
      return str;
    }
};
