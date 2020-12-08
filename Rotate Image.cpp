// https://leetcode.com/problems/rotate-image/

class Solution {
public:
    void rotate(vector<vector<int>>& arr) {
        int i, j, temp=0, n=arr.size();
        for(i=0;i<n/2;i++){
            for(j=0;j<n-1-2*i;j++){
                temp = arr[i][i+j];
                arr[i][i+j] = arr[n-1-i-j][i];
                arr[n-1-i-j][i] = arr[n-1-i][n-1-i-j];
                arr[n-1-i][n-1-i-j] = arr[i+j][n-1-i];
                arr[i+j][n-1-i] = temp;
            }
        }
        return;
    }
};