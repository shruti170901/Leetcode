// https://leetcode.com/problems/set-matrix-zeroes/

class Solution {
public:
    void setZeroes(vector<vector<int>>& mat) {
        int r1=1, c1=1, i, j, n, m;
        n=mat.size();
        if(n==0) return;
        m=mat[0].size();
        for(i=0;i<m;i++){
            if(mat[0][i]==0){r1=0; break;}
        }
        for(i=0;i<n;i++){
            if(mat[i][0]==0){c1=0; break;}
        }
        for(i=1;i<n;i++){
            for(j=1;j<m;j++){
                if(mat[i][j]==0){mat[i][0]=0; mat[0][j]=0;}
            }
        }
        for(i=1;i<n;i++){
            if(mat[i][0]==0){
                for(j=1;j<m;j++) mat[i][j]=0;
            }
        }
        for(i=1;i<m;i++){
            if(mat[0][i]==0){
                for(j=1;j<n;j++) mat[j][i]=0;
            }
        }
        if(r1==0){
            for(i=0;i<m;i++) mat[0][i]=0;
        }
        if(c1==0){
            for(i=0;i<n;i++) mat[i][0]=0;
        }
        return;
    }
};