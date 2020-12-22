class Solution
{
public:
    int maxPower(const string &s)
    {
        char ch = s[0];
        int res = 0, count = 1;
        for (int i = 1; i < s.size(); ++i)
        {
            if (s[i] != ch)
            {
                if (res < count)
                    res = count;
                ch = s[i];
                count = 1;
            }
            else
                ++count;
        }
        return max(res, count);
    }
};