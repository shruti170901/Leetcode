class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        if(!matrix.size()) 
           return false; 
        
        int m = matrix.size();
        int n = matrix[0].size();
        int l = 0;
        int r = (m * n) - 1;
        
        while(l <= r){
          
          int middle = (l + r) / 2;
          int i = middle / n;        // row in which middle will fall
          int j = middle % n;        //column in which middle will fall
          
          if(matrix[i][j] == target)
              return true;
          
          else if(matrix[i][j] < target)
              l = middle + 1;
          
          else
              r = middle - 1;
      }
      
      return false;
    }
};
