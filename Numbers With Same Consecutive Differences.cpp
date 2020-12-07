//Numbers With Same Consecutive Differences

class Solution
{
public:
    void dfs(int N, int K, int cur, int i, int prev, vector<int> &answer)
    {
        if (i == N - 1)
        {
            answer.push_back(cur);
            return;
        }
        int next = prev + K;
        if (next <= 9)
            dfs(N, K, (cur * 10) + next, i + 1, next, answer);

        next = prev - K;
        if (K != 0 && next >= 0)
            dfs(N, K, (cur * 10) + next, i + 1, next, answer);
    }

    vector<int> numsSameConsecDiff(int N, int K)
    {
        vector<int> answer;
        for (int i = 0; i <= 9; i++)
        {
            answer.push_back(i);
        }
        if (N != 1)
        {
            answer.clear();
            for (int i = 1; i <= 9; i++)
            {
                dfs(N, K, i, 0, i, answer);
            }
        }
        return answer;
    }
};