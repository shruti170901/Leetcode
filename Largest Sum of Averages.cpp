class Solution
{
public:
    double t[105][105];
    double Solve(vector<int> &arr, vector<double> &sum, int K, int n, int i)
    {
        if (i >= n)
        {
            return 0;
        }
        if (i == n - 1 || K == 0)
        {
            t[i][K] = (sum[n - 1] - sum[i] + arr[i]) / (n - i);
            return t[i][K];
        }
        if (t[i][K] != -1.0)
        {
            return t[i][K];
        }
        double ans = 0, temp;
        for (int j = i; j <= n - 1; j++)
        {
            double x = j - i + 1;
            temp = ((sum[j] - sum[i] + arr[i]) / x) + max(Solve(arr, sum, K - 1, n, j + 1), Solve(arr, sum, 0, n, j + 1));

            ans = max(temp, ans);
        }
        t[i][K] = ans;
        //cout<<ans<<endl;
        return ans;
    }
    double largestSumOfAverages(vector<int> &A, int K)
    {

        int n = A.size();
        vector<double> sum(n, 0);
        sum[0] = A[0];
        for (int i = 1; i < n; i++)
        {
            sum[i] = sum[i - 1] + A[i];
        }
        for (int i = 0; i < 105; i++)
        {
            for (int j = 0; j < 105; j++)
            {
                t[i][j] = -1.0;
            }
        }
        return max(Solve(A, sum, K - 1, n, 0), Solve(A, sum, 0, n, 0));
    }
};