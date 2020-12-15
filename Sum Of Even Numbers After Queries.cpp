class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& A, vector<vector<int>>& queries) {
        int sum = 0;
        for(int i=0; i<A.size(); i++) {
            if (A[i] % 2 == 0) sum += A[i];
        }
        vector<int> result;
        for(auto query : queries) {
            int i = query[1];
            int x = A[i] + query[0];
            
            if (A[i] % 2 == 0 && x %2 == 0) {
                sum += ( -A[i] + x ); 
                A[i] = x;
            } else if (A[i] % 2 != 0 && x %2 == 0) {
                sum += x;
                A[i] = x;
            } else if (A[i] % 2 == 0 && x %2 != 0) {
                sum -= A[i];
                A[i] = x;
            } else if (A[i] % 2 != 0 && x %2 != 0){ 
                A[i] = x;
            }
            result.push_back(sum);
        }
        
        if (result.size()<=0) result.push_back(0);
        return result;
    }
};
