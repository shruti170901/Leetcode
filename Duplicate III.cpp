class Solution
{
public:
    static bool pcomp(pair<int, int> a, pair<int, int> b)
    {
        return a.first < b.first;
    }

    bool search(vector<pair<int, int>> l, int t, int k)
    {
        int po = 0;
        while (po < l.size())
        {
            int i = po + 1;
            while (i < l.size())
            {
                if ((abs(long(l[i].first) - long(l[po].first)) <= t) && (abs(l[i].second - l[po].second) <= k))
                {
                    return true;
                }
                else
                {
                    if (abs(long(l[i].first) - long(l[po].first)) > t)
                    {
                        break;
                    }
                    else
                    {
                        i += 1;
                    }
                }
            }
            po += 1;
        }
        return false;
    }

    bool containsNearbyAlmostDuplicate(vector<int> &nums, int k, int t)
    {
        if (nums.size() == 0)
        {
            return false;
        }
        vector<pair<int, int>> pp;
        for (int i = 0; i < nums.size(); i++)
        {
            pp.push_back(make_pair(nums[i], i));
        }
        sort(pp.begin(), pp.end(), pcomp);
        return search(pp, t, k);
    }
};