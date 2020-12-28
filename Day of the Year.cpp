class Solution
{
public:
    bool isLeap(int y)
    {

        return (y % 4 == 0 && y % 100 != 0) || (y % 400 == 0);
    }

    int getMonth(int m, int y)
    {

        if (m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12)
            return 31;
        if (m == 2)
            return isLeap(y) ? 29 : 28;
        return 30;
    }

    int dayOfYear(string date)
    {

        int y = stoi(date.substr(0, 4));
        int m = stoi(date.substr(5, 7));
        int d = stoi(date.substr(8, 10));

        int days = 0;
        days += d;

        for (int month = 1; month < m; month++)
        {
            days += getMonth(month, y);
        }

        return days;
    }
};