

class Solution 
{
public:
    bool validTicTacToe(vector<string>& board) {
        
        
        
        int move_X = 0, move_O = 0;
        bool win_X = false, win_O = false;
        vector<int> row(3), col(3);
        int dia = 0, undia = 0;
        for(int i = 0; i < 3;++i)
        {
            for(int j = 0; j < 3; ++j)
            {
                int count = board[i][j]=='X'?1:0;
                count = board[i][j]=='O'?-1:count;
                row[i]+=count;
                col[j]+=count;
                if(i==j) 
                    dia+=count;
                if(i+j==2) 
                    undia+=count;
                move_X+=board[i][j]=='X'?1:0;
                move_O+=board[i][j]=='O'?1:0;
            }
        }
        if(row[0]==3||row[1]==3||row[2]==3||dia==3||undia==3||col[0]==3||col[1]==3||col[2]==3) 
            win_X = true;
        if(row[0]==-3||row[1]==-3||row[2]==-3||dia==-3||undia==-3||col[0]==-3||col[1]==-3||col[2]==-3) 
            win_O = true;
        if(move_O>move_X||move_O<move_X-1) 
            return false; // X move must be last most one step ahead
        if(win_X && move_X<=move_O) 
            return false; // x win, x must be one step ahead of o
        if(win_O&&move_X>move_O) 
            return false; // O win, X must be equal step of o
        return true;
        
    }
};