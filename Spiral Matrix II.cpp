
/*a positive integer n, generate an n x n matrix filled with elements from 1 to n2 in spiral order.*/
Input : n=3
Output : [[1,2,3],[8,9,4],[7,6,5]]

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        //Here We will create a 2D matrix n x n using vector
        vecor<vector<int> >ans(n);
        for(int i=0;i<n;i++){
             ans.resize(n);
        }
        int cnt=1; 
        int i=0,j=n-1;
        while(cnt<=n*n){
            //Moving top row from left to right
            for(int k=i;k<=j;k++){
                ans[i][k]=cnt;
                cnt++;
            }
            //Moving right column from top to bottom
            for(int l=i+1;l<=j; l++){
                ans[l][j]=cnt;
                cnt++;
            }
            //Moving bottom row from right to left
            for(int m=j-1;m>=i;m--){
                ans[j][m]=cnt;
                cnt++;
            }
            //Moving left column from bottom to top
            for(int p=j-1;p>i;p--){
                ans[p][i]=cnt;
                cnt++;
            }
            j--;
            i++;
         }
        return ans;//return 2D vector
    }
};
