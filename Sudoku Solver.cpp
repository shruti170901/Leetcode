// https://leetcode.com/problems/sudoku-solver/

class Solution {
public:
    bool check(vector<vector<char>>&board, int i, int j, char c){
        int x=3*(i/3), y=3*(j/3);
        for(int k=0;k<9;k++) if(board[k][j]==c) return false;
        for(int k=0;k<9;k++) if(board[i][k]==c) return false;
        for(int k=0;k<3;k++){
            for(int l=0;l<3;l++){
                if(board[x+k][y+l]==c) return false;
            }
        }
        return true;
    }
    bool solve(vector<vector<char>> &board, int i, int j){
        if(j==9) return solve(board, i+1, 0);
        if(i==9) return true;
        if(board[i][j]!='.') return solve(board, i, j+1);
        for(char c='1';c<='9';c++){
            if(check(board, i, j, c)){
                board[i][j]=c;
                if(solve(board, i, j+1)) return true;
                board[i][j]='.';
            }
        }
        return false;
    }
    void solveSudoku(vector<vector<char>>& board) {
        solve(board, 0, 0);
    }
};