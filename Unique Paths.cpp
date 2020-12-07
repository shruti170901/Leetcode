//concept.....using recursion
class Solution {
public:
    int uniquePaths(int m, int n) {
        if(m==1 || n==1) return 1;
        int x,y;
        //right is chosen
        x = uniquePaths( m, n-1);
    
        //down is chosen
        y = uniquePaths( m-1, n);
        
        return x+y;
    }
};

//effective solution using DP
class Solution {
public:
    int uniquePaths(int m, int n) {
        if(m==1 || n==1) return 1;
        int x[m][n];
        x[0][0] = 1;
        for(int i=1; i<n; i++)
            x[0][i]=1;
        for(int i=1; i<m; i++)
            x[i][0]=1;
        for(int i=1; i<m; i++){
            for(int j=1; j<n; j++){
                x[i][j] = x[i-1][j]+x[i][j-1];
            }
        }
        return x[m-1][n-1];
    }
};