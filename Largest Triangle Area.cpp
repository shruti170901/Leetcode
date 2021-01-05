class Solution
{
public:
    double largestTriangleArea(vector<vector<int>> &p)
    {
        double maxArea = 0;
        for (int i = 0; i < p.size(); i++)
        {
            for (int j = 0; j < p.size() - 1; j++)
            {
                for (int k = 0; k < p.size() - 2; k++)
                {
                    double a = sqrt(pow(p[i][0] - p[j][0], 2) +
                                    pow(p[i][1] - p[j][1], 2));
                    double b = sqrt(pow(p[i][0] - p[k][0], 2) +
                                    pow(p[i][1] - p[k][1], 2));
                    double c = sqrt(pow(p[j][0] - p[k][0], 2) +
                                    pow(p[j][1] - p[k][1], 2));
                    double semiPerimeter = (a + b + c) / 2;
                    double area = sqrt(semiPerimeter * (semiPerimeter - a) * (semiPerimeter - b) * (semiPerimeter - c));
                    maxArea = max(maxArea, area);
                }
            }
        }
        return maxArea;
    }
};