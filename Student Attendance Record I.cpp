class Solution {
public:
    bool checkRecord(string s) 
    {
        int i, counter = 0;
        for (i=0;i<s.length();i++) 
        {
            if (s[i] == 'A') 
            {
                counter++;
                if (counter==2) 
                {
                    return false;
                }
            }
            if ((i+2<s.length())&&(s[i]=='L')&&(s[i+1]=='L')&&(s[i+2]=='L')) 
            {
                return false;
            }
        }
        return true;
    }
};