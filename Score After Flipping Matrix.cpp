// https://leetcode.com/problems/score-after-flipping-matrix/

class Solution {
public:
    int matrixScore(vector<vector<int>>& A) {
        int i, j, ans=0, m=A.size(), n=A[0].size(), cnt;
        for(i=0;i<m;i++){
            if(A[i][0]==0){
                for(j=0;j<n;j++){
                    A[i][j]^=1;
                }
            }
        }
        ans=(1<<(n-1))*m;
        for(j=1;j<n;j++){
            cnt=0;
            for(i=0;i<m;i++){
                cnt+=A[i][j];
            }
            ans+=(1<<(n-1-j))*max(cnt, m-cnt);
        }
        return ans;
    }
};