class Solution
{
public:
    int longestOnes(vector<int> &A, int K)
    {
        int left = 0;
        int ans = 0;
        int count = 0;
        for (int i = 0; i < A.size(); i++)
        {
            if (A[i] == 0)
            {
                count++;
            }
            while (count > K)
            {
                if (A[left] == 0)
                {
                    count--;
                }
                left++;
            }
            ans = max(ans, i - left + 1);
        }
        return ans;
    }
};