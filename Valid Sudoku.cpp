// https://leetcode.com/problems/valid-sudoku/

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int i, j, l, k;
        bitset<9> b1;
        for(i=0;i<9;i++){
            b1.reset();
            for(j=0;j<9;j++){
                char c=board[i][j];
                if(c!='.'){
                    if(b1[c-'0']) return false;
                    b1[c-'0']=1;
                }
            }
        }
        for(i=0;i<9;i++){
            b1.reset();
            for(j=0;j<9;j++){
                char c=board[j][i];
                if(c!='.'){
                    if(b1[c-'0']) return false;
                    b1[c-'0']=1;
                }
            }
        }
        for(i=0;i<9;i+=3){
            for(j=0;j<9;j+=3){
                b1.reset();
                for(l=0;l<3;l++){
                    for(k=0;k<3;k++){
                        char c=board[i+l][j+k];
                        if(c!='.'){
                            if(b1[c-'0']) return false;
                            b1[c-'0']=1;
                        }
                    }
                }
            }
        }
        return true;
    }
};