class Solution {
public:
    int shift(vector<vector<int>>&A,vector<vector<int>>&B)
    {
        int n=B.size();
        int count=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                int x=0;
                for(int k=i;k<n;k++)
                {
                    for(int l=j;l<n;l++)
                    {
                        if(B[k][l]==1&&A[k-i][l-j]==1)
                            x++;
                    }
                }
                count=max(count,x);
            }
        }
        return count;
    }
    int largestOverlap(vector<vector<int>>& A, vector<vector<int>>& B) {
        return max(shift(A,B),shift(B,A));
        
    }
};