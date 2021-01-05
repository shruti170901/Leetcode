class Solution
{
public:
    vector<int> numMovesStones(int a, int b, int c)
    {
        int x[3];
        int min, max;
        vector<int> ans;
        x[0] = a;
        x[1] = b;
        x[2] = c;
        sort(x, x + 3);
        if (x[0] == x[1] - 1 && x[1] == x[2] - 1)
            min = 0;
        else if (x[0] + 2 == x[1] || x[1] + 2 == x[2] || x[0] + 1 == x[1] || x[1] + 1 == x[2])
            min = 1;
        else
            min = 2;
        int i = 0;
        while (x[0] + 1 != x[1])
        {
            i++;
            x[0]++;
        }
        int j = 0;
        while (x[2] - 1 != x[1])
        {
            j++;
            x[2]--;
        }
        max = i + j;
        ans.push_back(min);
        ans.push_back(max);
        return ans;
    }
};