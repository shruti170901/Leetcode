class Solution {
public:
        int countVowelStrings(int n) {
        int dp[n][5];
        //dp[i][j] represents total no. of string of length i , using all character from j to end. Hence answer is dp[n][0]
        
        for(int j=4; j>=0; j--)
            dp[0][j] = 5-j;// intialize first row
        
        for(int i=1; i<n; i++){
            for(int j=4; j>=0; j--){ //a=0, e=1, i=2, o=3, u=4
                if(j == 4)//last column (starting with u) and after is always 1
                    dp[i][j] = 1;
                else
                    dp[i][j] = dp[i-1][j] + dp[i][j+1];// one less character i.e of length i-1(here we append j in beginning) + all starting with characters after j of length i.
                    
            }
        }
        return dp[n-1][0];
        
        
    }
};
