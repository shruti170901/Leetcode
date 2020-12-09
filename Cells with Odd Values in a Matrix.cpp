// https://leetcode.com/problems/cells-with-odd-values-in-a-matrix/

class Solution {
public:
    int oddCells(int n, int m, vector<vector<int>>& indices) {
        int row[51]={0}, col[51]={0}, i, j, ans=0;
        for(i=0;i<indices.size();i++){
            row[indices[i][0]]++;
            col[indices[i][1]]++;
        }
        for(i=0;i<n;i++){
            for(j=0;j<m;j++){
                if((row[i]+col[j])%2) ans++;
            }
        }
        return ans;
    }
};