class Solution {
public:
   vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> res(n,vector<int>(n));
        int top = 0, bottom = n-1, left = 0,right = n-1;
        int direction =0;
		/*
		0 - left to right
		1 - top to bottom
		2 - right to left
		3 - bottom to top
		*/
        int num = 1;
        while(top<=bottom && left<=right){
            if(direction==0){
                direction=1;
                for(int i=left;i<=right;i++){
                    res[top][i] = num;
                    num++;
                }
                top++;
            }
            else if(direction == 1){
                direction=2;
                for(int i=top;i<=bottom;i++){
                    res[i][right] = num;
                    num++;
                }
                right--;
            }
            else if(direction == 2){
                direction=3;
                for(int i=right;i>=left;i--){
                    res[bottom][i] = num;
                    num++;
                }
                bottom--;
            }
            else{
                direction=0;
                for(int i=bottom;i>=top;i--){
                    res[i][left] = num;
                    num++;
                }
                left++;
            }
        }
        return res;
    }
};