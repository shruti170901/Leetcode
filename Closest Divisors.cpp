class Solution
{
public:
    vector<int> closestDivisors(int num)
    {
        auto [a, b] = min(factor(num + 1), factor(num + 2));
        return {b, a};
    }
    pair<int, int> factor(int n)
    {
        int i;
        for (i = sqrt(n); i > 0 && n % i; i--)
            ;
        return {n / i, i};
    }
};