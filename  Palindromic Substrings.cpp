class Solution
{
    vector<vector<int>> dp, visited;

public:
    int calc(int i, int j, string &s)
    {

        if (i >= j)
        {
            visited[i][j] = 1;
            return 1;
        }

        if (visited[i][j])
        {
            return dp[i][j];
        }
        if (s[i] == s[j] && !visited[i][j])
        {
            visited[i][j] = 1;
            dp[i][j] = calc(i + 1, j - 1, s);
            return dp[i][j];
        }
        else
        {
            visited[i][j] = 1;
            dp[i][j] = 0;
            return 0;
        }
    }
    int countSubstrings(string s)
    {

        int i, j;
        int n = s.size();
        int ans = 0;

        dp.resize(n, vector<int>(n, -1));
        visited.resize(n, vector<int>(n, 0));

        for (i = 0; i < n; i++)
        {
            for (j = i; j < n; j++)
            {
                ans += calc(i, j, s);
            }
        }

        return ans;
    }
};