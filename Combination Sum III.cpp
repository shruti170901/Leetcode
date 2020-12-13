class Solution
{
public:
    vector<vector<int>> v;
    void sol(int k, int n, vector<int> &temp, int l)
    {
        if ((k == 0 && n != 0) || n < 0)
            return;
        if (k == 0 && n == 0)
        {
            v.push_back(temp);
            return;
        }
        for (int i = l; i <= 9; i++)
        {
            vector<int> t(temp);
            t.push_back(i);
            sol(k - 1, n - i, t, i + 1);
            t.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n)
    {
        //vector<int> temp;
        for (int i = 1; i <= 9; i++)
        {
            vector<int> temp;

            temp.push_back(i);

            sol(k - 1, n - i, temp, i + 1);

            temp.pop_back();
        }

        //   sol(k,n,temp,1);

        return v;
    }
};