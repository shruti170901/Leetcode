class Solution
{
public:
    int minEatingSpeed(vector<int> &piles, int H)
    {
        sort(piles.begin(), piles.end());
        int n = piles.size();
        int minspeed = 1, maxspeed = piles[n - 1];

        while (minspeed < maxspeed)
        {
            int eatingspeed = (minspeed + maxspeed) / 2;

            if (possible(eatingspeed, piles, H))
                maxspeed = eatingspeed;
            else
                minspeed = eatingspeed + 1;
        }
        return maxspeed;
    }

    bool possible(int eatingspeed, vector<int> &piles, int H)
    {
        int sum = 0;
        for (int i = 0; i < piles.size(); i++)
        {
            int val = piles[i];
            if (val % eatingspeed == 0)
                sum += val / eatingspeed;
            else
                sum += val / eatingspeed + 1;
        }
        if (sum <= H)
            return true;
        return false;
    }
};