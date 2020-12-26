class Solution {
public:
    bool repeatedSubstringPattern(string s) {
       int n=s.length();
        for(int i=n/2;i>0;i--)
        {
            if(n%i==0)
            {
                int j=0;
                while(i+j<n&&s[i+j]==s[j])
                    j++;
                if(i+j==n)
                    return true;
            }
        }
        return false;
        
    }
};