class Solution
{
public:
    int rotatedDigits(int N)
    {
        int count = 0;
        for (int i = 1; i <= N; i++)
        {
            int temp = i;
            int flag = 0;
            while (temp != 0)
            {
                if (temp % 10 == 3 || temp % 10 == 4 || temp % 10 == 7)
                {
                    flag = 1;
                    break;
                }
                if (temp % 10 == 2 || temp % 10 == 5 || temp % 10 == 6 || temp % 10 == 9)
                {
                    flag = 2;
                }
                temp = temp / 10;
            }
            if (flag == 2)
                count++;
        }
        return count;
    }
};