// Number of Ways of Cutting a Pizza
// https://leetcode.com/problems/number-of-ways-of-cutting-a-pizza/
class Solution {
public:
    int dp[51][51][10],n,m,M=(int)1e9+7;
    long long add(long long A,long long B){
        A+=B;
        if(A>=M)A-=M;
        return A;
    }
    long long f(int r,int c,vector<string>&a,int k,int left){
        long long ans=0;
        if(dp[r][c][k]!=-1)return dp[r][c][k];
        if(k==1){
            //if atleast one apple
            if(left!=0)return 1;
            //else
            return 0;
        }
        int row_apple=0;
        for(int i=n-1;i>r;i--){
            for(int j=c;j<m;j++){
                row_apple+=(a[i][j]=='A');
            }
            if(left-row_apple>0 and row_apple>0){
                ans=add(ans,f(i,c,a,k-1,row_apple));
            }
        }
        int col_apple=0;
        for(int j=m-1;j>c;j--){
            for(int i=r;i<n;i++){
                col_apple+=(a[i][j]=='A');
            }
            if(left-col_apple>0 and col_apple>0){
                ans=add(ans,f(r,j,a,k-1,col_apple));
            }
        }
        return dp[r][c][k]=ans;
    }
    int ways(vector<string>& a, int k) {
        n=a.size(),m=a[0].size();memset(dp,-1,sizeof dp);
        int cnt=0;
            for(int i=0;i<n;i++)
                for(int j=0;j<m;j++)
                    cnt+=(a[i][j]=='A');
        return f(0,0,a,k,cnt);
    }
};
