// https://leetcode.com/problems/flipping-an-image/

class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {
        int i, j, n=A.size(), m=A[0].size();
        for(i=0;i<n;i++){
            reverse(A[i].begin(), A[i].end());
            for(j=0;j<m;j++) A[i][j]^=1;
        }
        return A;
    }
};