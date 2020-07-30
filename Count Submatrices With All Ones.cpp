class Solution {
public:
    void findPrefixCount(vector<vector<int>>& p_arr, vector<vector<int>>& mat) { 
        int col = mat[0].size();
        int row = mat.size();
        for (int i = 0; i < row; i++) { 
            for (int j = col - 1; j >= 0; j--) { 
                if (!mat[i][j]) 
                    continue; 
                if (j != col - 1) 
                    p_arr[i][j] += p_arr[i][j + 1]; 
                p_arr[i][j] += mat[i][j]; 
            } 
        } 
    } 
    
    int numSubmat(vector<vector<int>>& mat) {
        int col = mat[0].size();
        int row = mat.size();
        vector<vector<int>> arr = mat;
        vector<vector<int>> p_arr( row, vector<int>(col,0));
        findPrefixCount(p_arr, arr);
        int ans = 0;
        for (int j = 0; j < col; j++) { 
            int i = row - 1; 
            stack<pair<int, int> > q; 
            int to_sum = 0; 
            while (i >= 0) { 
                int c = 0; 
                while (q.size() != 0 and q.top().first > p_arr[i][j]) { 
                    to_sum -= (q.top().second + 1) *  
                                (q.top().first - p_arr[i][j]); 
                    c += q.top().second + 1; 
                    q.pop(); 
                } 
                to_sum += p_arr[i][j];
                ans += to_sum; 
                q.push({ p_arr[i][j], c });
                i--; 
            } 
        }
        return ans;
    }
};
