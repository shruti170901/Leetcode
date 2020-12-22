class Solution
{
public:
    int maxTurbulenceSize(vector<int> &A)
    {
        int high = 1, low = 1;
        int ans = 1;
        for (int i = 1; i < A.size(); i++)
        {
            if (A[i] > A[i - 1])
            {
                high = 1 + low;
                low = 1;
            }
            else if (A[i] == A[i - 1])
                high = low = 1;
            else
            {
                low = 1 + high;
                high = 1;
            }
            ans = max(ans, max(low, high));
        }
        return ans;
    }
};