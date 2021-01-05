/*   https://leetcode.com/problems/diagonal-traverse/
    Given a matrix of M x N elements (M rows, N columns), return all elements of the matrix in diagonal order as shown in the below image.
    
    
    Input:
[
 [ 1, 2, 3 ],
 [ 4, 5, 6 ],
 [ 7, 8, 9 ]
]

Output:  [1,2,4,7,5,3,6,8,9]

*/

class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        int m=matrix.size();
        if(m==0)
            return ans;
        int n=matrix[0].size();
        //int times=(m+n)-1;
        int k=1;
        int i=0,j=0;
        stack<int> temp;
        while(i<m)
        {
            if(k%2!=0)
            {
                int temp_i=i,temp_j=j;
                for(;temp_i>=0&&temp_j<n;temp_i--,temp_j++)
                {
                    ans.push_back(matrix[temp_i][temp_j]);
                }
            }
            else
            {
                int temp_i=i,temp_j=j;
                for(;temp_i>=0&&temp_j<n;temp_i--,temp_j++)
                {
                    temp.push(matrix[temp_i][temp_j]);
                }
                while(!temp.empty())
                {
                    ans.push_back(temp.top());
                    temp.pop();
                }
            }
            k++;
            i++;
        }
        i=m-1,j=1;
        while(j<n)
        {
            if(k%2!=0)
            {
                int temp_i=i,temp_j=j;
                for(;temp_i>=0&&temp_j<n;temp_i--,temp_j++)
                {
                    ans.push_back(matrix[temp_i][temp_j]);
                }
            }
            else
            {
                int temp_i=i,temp_j=j;
                for(;temp_i>=0&&temp_j<n;temp_i--,temp_j++)
                {
                    temp.push(matrix[temp_i][temp_j]);
                }
                while(!temp.empty())
                {
                    ans.push_back(temp.top());
                    temp.pop();
                }
            }
            k++;
            j++;
        }
        return ans;
    }
};
    
