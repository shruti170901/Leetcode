class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
      int n = matrix.size();
      int m = matrix[0].size();
      int ans = INT_MIN;
      for(int l = 0; l < m; l++){
         vector <int> rowSum(n);
         for(int r = l; r < m; r++){
            for(int i = 0; i < n; i++)rowSum[i] += matrix[i][r];
            set < int > s;
            s.insert(0);
            int currSum = 0;
            for(int i = 0; i < n; i++){
               currSum += rowSum[i];
               set <int> :: iterator it = s.lower_bound(currSum - k);
               if(it != s.end()){
                  ans = max(ans, (currSum - *it));
               }
               s.insert(currSum);
            }
         }
      }
      return ans;
    }
};
