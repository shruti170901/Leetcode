// https://leetcode.com/problems/spiral-matrix-ii/

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> v(n, vector<int>(n));
        if(n==0) return v;
        int i=0, j=0, l, r, u, d, flag=0, cnt=1;
        l=0; r=n-1; u=0; d=n-1;
        while(cnt<=n*n){
            if(flag==0){
                if(j<r){v[i][j++]=cnt;}
                else{
                    v[i][j]=cnt;
                    flag=1;
                    u=i+1;
                    i++;
                }
            }
            else if(flag==1){
                if(i<d){v[i++][j]=cnt;}
                else{
                   v[i][j]=cnt;
                    flag=2;
                    r=j-1;
                    j--;
                }
            }
            else if(flag==2){
                if(j>l) v[i][j--]=cnt;
                else{
                    v[i][j]=cnt;
                    flag=3;
                    d=i-1;
                    i--;
                }
            }
            else{
                if(i>u) v[i--][j]=cnt;
                else{
                    v[i][j]=cnt;
                    flag=0;
                    l=j+1;
                    j++;
                }
            }
            cnt++;
        }
        return v;
    }
};