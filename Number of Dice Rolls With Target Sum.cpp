/* 
Leetcode
You have d dice, and each die has f faces numbered 1, 2, ..., f.
Return the number of possible ways (out of f^d total ways) modulo 10^9 + 7 to roll the dice so the sum of the face up numbers equals target.
Input: d = 1, f = 6, target = 3
Output: 1
Input: d = 2, f = 6, target = 7
Output: 6
Input: d = 30, f = 30, target = 500
Output: 222616187
*/


#define K 1000000007
typedef long long int lli;
class Solution {
public:
    
    int numRollsToTarget(int N, int M, int X) {
        int **Dp=(int **)malloc((N+1)*sizeof(int *));
        for(int i=0;i<=N;i++)
            Dp[i]=(int *)malloc((X+1)*sizeof(int));
        for(int i=0;i<=N;i++)
        {
            if(i==0)
                Dp[i][0]=1;
            else
                Dp[i][0]=0;
        }
        for(int i=1;i<=X;i++)
        {
            Dp[0][i]=0;
        }
        for(int i=1;i<=N;i++)
        {
            int iptr=0,jptr=-1;
            lli sum=0;
            for(int j=1;j<=X;j++)
            {
                jptr++;
                sum+=(lli)Dp[i-1][jptr];//(sum+(Dp[i-1][jptr])%K)%K;
                if(jptr-iptr+1>M)
                {
                    sum-=(lli)Dp[i-1][iptr];//(sum-(Dp[i-1][iptr])%K)%K;
                    iptr++;
                }
                Dp[i][j]=sum%K;
            }
        }
        int ans=Dp[N][X];
        for(int i=0;i<=N;i++)
            free(Dp[i]);
        free(Dp);
        return ans;
    }
};
