class Solution
{
public:
    bool rotateString(string A, string B)
    {
        if (A.size() != B.size())
            return false;
        //empty strings
        if (A == B)
            return true;

        int len = B.size();
        while (len--)
        {
            if (A == B)
                return true;
            A = A.substr(1) + A[0];
        }
        return false;
    }
};