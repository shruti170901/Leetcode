class Solution
{
public:
    int maxSatisfied(vector<int> &customers, vector<int> &grumpy, int x)
    {
        int initial_satisfied = 0;

        for (int i = 0; i < customers.size(); i++)
        {
            if (grumpy[i] == 0)
            {
                initial_satisfied += customers[i];
            }
        }
        int mx = 0, sum = 0;
        int start = 0, end = 0;
        int n = customers.size();

        while (end < n)
        {
            if (grumpy[end] == 1)
            {
                sum += customers[end];
            }
            if (end + 1 >= x)
            {
                mx = max(sum, mx);
                if (grumpy[start] == 1)
                {
                    sum -= customers[start];
                }
                start++;
            }
            end++;
        }
        return initial_satisfied + mx;
    }
};