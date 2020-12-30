class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int r=matrix.size();
        if(r==0){
            return false;
        }
        int c=matrix[0].size();
        if(c==0){
            return false;
        }
        int i=0,j=c-1;
        while(i<r&&j>-1){
            if(target==matrix[i][j]){
                return true;
            }
            else if(target>matrix[i][j]){
                i++;
            }
            else{
                j--;
            }
        }
        return false;
    }   
};
