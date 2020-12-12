class Solution {
    int dp[1001][1001];
public:
    string shortestCommonSupersequence(string X, string Y) {
        int n=X.length();
        int m=Y.length();
        for(int i=0;i<=n;i++)
        dp[i][0]=0;            // base case initialisation
    for(int j=0;j<=m;j++)
        dp[0][j]=0;  

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
                                   // choice diagram
            if(X[i-1]==Y[j-1])
                dp[i][j]=1+dp[i-1][j-1];
            else
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
        
        }
    }  
    int length=m+n-dp[n][m];
    char scs[length+1];
    scs[length]='\0';
    length--;
    int i=n,j=m;
    while(i>0&&j>0){
        if(X[i-1]==Y[j-1]){
            scs[length]=X[i-1];
            length--;
            i--;
            j--;
        }
        else{
            if(dp[i-1][j]>dp[i][j-1]){
                scs[length]=X[i-1];
                length--;
                i--;
            }
            else
            {   
                scs[length]=Y[j-1];
                length--;
                j--;
            }
            
        }
    }
    while(i>0){
        scs[length]=X[i-1];
        i--;
        length--;
    }
    while(j>0){
        scs[length]=Y[j-1];
        j--;
        length--;
    }
    return scs;
    }
};
