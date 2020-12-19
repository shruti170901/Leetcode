class Solution {
public:
    string licenseKeyFormatting(string str, int K)
    {
        std::transform(str.begin(), str.end(),str.begin(), ::toupper);
        str.erase(std::remove(str.begin(), str.end(), '-'), str.end());
        int len = str.length();
        if(K >= len )
            return str;
       
        int firstPos = len % K;
       
        if( firstPos == 0 )
        {
            int segments = len / K;
            firstPos = len /segments ;
        }
        str.insert(firstPos, 1, '-');
       
        for(int i = firstPos+K+1; i < str.size(); i +=K+1)
        {
           str.insert(i, 1, '-');
        }
        return str;
    }
};
