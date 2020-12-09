// https://leetcode.com/problems/count-negative-numbers-in-a-sorted-matrix/

class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int cnt=0, m=grid.size(), n=grid[0].size();
        int i=m-1, j=0;
        while(i>=0 && j<n){
            while(j<n && grid[i][j]>=0) j++;
            if(j>=n) break;
            cnt+=n-j;
            i--;
        }
        return cnt;
    }
};