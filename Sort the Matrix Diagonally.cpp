// https://leetcode.com/problems/sort-the-matrix-diagonally/

class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        int i, j, n=mat.size(), m=mat[0].size();
        vector<int> v;
        i=n-1; j=0;
        while(i>=0){
            v.clear();
            for(int k=0; i+k<n && j+k<m;k++){
                v.push_back(mat[i+k][j+k]);
            }
            sort(v.begin(), v.end());
            for(int k=0; i+k<n && j+k<m;k++){
                mat[i+k][j+k]=v[k];
            }
            i--;
        }
        i++; j++;
        while(j<m){
            v.clear();
            for(int k=0; i+k<n && j+k<m;k++){
                v.push_back(mat[i+k][j+k]);
            }
            sort(v.begin(), v.end());
            for(int k=0; i+k<n && j+k<m;k++){
                mat[i+k][j+k]=v[k];
            }
            j++;
        }
        return mat;
    }
};