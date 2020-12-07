class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> result;
        int row = matrix.size();
        if(!row) 
        return result;
        int col = matrix[0].size();
        int left = 0;
        int right = col-1;
        int top = 0;
        int bottom = row-1;
        int direction = 0;

        /*
            direction==0     left to right
            direction==1     top to bottom
            direction==2     right to left
            direction==3     bottom to top

        */


        while(left <= right && top <= bottom)
        {
            if(direction == 0)
            {
                direction =1;
                for(int i = left; i <= right;i++)
                {
                    result.push_back(matrix[top][i]);
                }
                top++;
            }
            else if(direction == 1)
            {
                direction =2;
                for(int i = top; i <= bottom;i++)
                {
                    result.push_back(matrix[i][right]);
                }
                right--;
            }
            else if (direction == 2)
            {
                direction = 3;
                for(int i = right; i >= left;i--)
                {
                    result.push_back(matrix[bottom][i]);
                }
                bottom--;
            }
            else {
                direction = 0;
                for(int i = bottom; i >= top;i--)
                {
                    result.push_back(matrix[i][left]);
                }
                left++;
            }
        }
        return result;
        
    }
};