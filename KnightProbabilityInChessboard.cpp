class Solution {
public:
    int dx[8] = {2,2,1,-1,-2,-2,1,-1};
    int dy[8] = {1,-1,2,2,1,-1,-2,-2};
    double knightProbability(int N, int K, int r, int c) {
        vector<vector<double> > dp0(N,vector<double> (N,1));
        int i,j;
        for(int l=0;l<K;l++)
        {
            vector<vector<double> > dp1(N,vector<double> (N,0));
            for(i=0;i<N;i++)
            {
                for(j=0;j<N;j++)
                {
                    int k;
                    for(k=0;k<8;k++)
                    {
                        int nx = i+dx[k];
                        int ny = j+dy[k];
                        if(nx<N && nx>=0 && ny<N && ny>=0)
                        {
                            dp1[i][j] += dp0[nx][ny];
                        }
                    }
                }
            }
            swap(dp0,dp1);
        }
        return dp0[r][c]/pow(8,K);
    }
};
