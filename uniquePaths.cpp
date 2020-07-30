class Solution {
public:
    int uniquePaths(int m, int n) {
        int path[m*n];
        for(int i = 0; i < m; i++)
            for(int j = 0; j < n; j++)
            {
                if(i == 0 || j == 0)
                    path[j*m+i] = 1;
                else
                    path[j*m+i] = path[(j-1)*m+i] + path[j*m+i-1];
            }
        return path[m*n-1];
    }
};
