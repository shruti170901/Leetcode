// https://leetcode.com/problems/search-a-2d-matrix/

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& mat, int target) {
        int i, j, n, m, l, r, mid;
        n=mat.size();
        if(n==0) return false;
        m=mat[0].size();
        l=0; r=n*m-1;
        while(l<=r){
            mid=l+(r-l)/2;
            i=mid/m; j=mid%m;
            if(mat[i][j]==target) return true;
            else if(target<mat[i][j]) r=mid-1;
            else l=mid+1;
        }
        return false;
    }
};